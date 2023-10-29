#include <vector>
#include <iostream>
#include "data_handler.h"
#include "database_connection.h"

namespace persistence {

std::vector<game::PackageModel> DataHandler::GetPackages() const {
  std::vector<game::PackageModel> packages;

  const char* sql = "SELECT inhoud, bestemming FROM pakketjes";

  DatabaseConnection& connection = DatabaseConnection::GetInstance();

  try {
    connection.ExecuteQuery(sql);
  } catch (const std::runtime_error &ex) {
    throw;
  }

  auto statement = connection.PrepareStatement(sql);

  if (!statement) return packages;

  while (sqlite3_step(statement.get()) == SQLITE_ROW) {
    const char* content_description = reinterpret_cast<const char*>(sqlite3_column_text(statement.get(), 0));
    const char* destination_description = reinterpret_cast<const char*>(sqlite3_column_text(statement.get(), 1));

    game::PackageModel package;
    package.description_ = content_description ? content_description : "";
    package.destination_ = destination_description ? destination_description : "";

    packages.push_back(package);
  }

  return packages;
}

std::vector<game::EncounterModel> DataHandler::GetEncounters() const {
  std::vector<game::EncounterModel> encounters;

  const char* sql = R"(
    SELECT ontmoetingen.ID, ontmoetingen.omschrijving, consequenties.bron, consequenties.type, aantal, tekst
    FROM ontmoetingen
    LEFT JOIN consequenties ON ontmoetingen.ID = consequenties.ontmoetingID
    LEFT JOIN consequentietypes ON consequenties.type = consequentietypes.type
    LEFT JOIN consequentiebronnen ON consequenties.bron = consequentiebronnen.bron
  )";

  DatabaseConnection& connection = DatabaseConnection::GetInstance();

  try {
    connection.ExecuteQuery(sql);
  } catch (const std::runtime_error &ex) {
    throw;
  }

  auto statement = connection.PrepareStatement(sql);

  if (statement) {
    while (sqlite3_step(statement.get()) == SQLITE_ROW) {
      int encounter_id = sqlite3_column_int(statement.get(), 0);
      std::string encounter_description = GetStringColumn(statement.get(), 1);

      auto existing_encounter = FindEncounterByID(encounters, encounter_id);

      if (existing_encounter == encounters.end()) {
        game::EncounterModel new_encounter;
        new_encounter.id = encounter_id;
        new_encounter.description = encounter_description;
        encounters.push_back(new_encounter);
        existing_encounter = encounters.end() - 1;
      }

      game::Consequence new_consequence = CreateConsequenceFromRow(statement.get());
      existing_encounter->consequences.push_back(new_consequence);
    }
  }

  return encounters;
}

std::vector<game::EncounterModel, std::allocator<game::EncounterModel>>::iterator
DataHandler::FindEncounterByID(std::vector<game::EncounterModel>& encounters, int id) {
  return std::find_if(
      encounters.begin(),
      encounters.end(),
      [id](const game::EncounterModel& encounter) {
        return encounter.id == id;
      });
}

game::Consequence DataHandler::CreateConsequenceFromRow(sqlite3_stmt* statement) const {
  game::Consequence new_consequence;
  new_consequence.amount = sqlite3_column_int(statement, 4);
  new_consequence.description = GetStringColumn(statement, 5);
  new_consequence.consequence_source = game::enums::GetEncounterCharacterFromString(GetStringColumn(statement, 2));
  new_consequence.consequence_type = game::enums::GetEncounterConsequenceTypeFromString(GetStringColumn(statement, 3));

  return new_consequence;
}

std::string DataHandler::GetStringColumn(sqlite3_stmt* statement, int column_index) {
  const char* text = reinterpret_cast<const char*>(sqlite3_column_text(statement, column_index));
  return text ? text : "";
}

}
