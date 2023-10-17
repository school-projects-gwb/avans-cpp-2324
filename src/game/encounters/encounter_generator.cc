#include "encounter_generator.h"
#include "helpers/random_helper.h"
#include <iostream>

namespace game {

EncounterGenerator::EncounterGenerator(std::vector<EncounterModel>& encounters) : encounters_(encounters) {

}

void EncounterGenerator::GenerateResult(SpaceshipStats& spaceship_stats, enums::EncounterCharacter encounter_character) {
  AddEncounterLogRecord("Je koos: " + enums::GetEncounterCharacterFromEnum(encounter_character));
  auto source = encounter_character == enums::Bender ? GetRandomCharacter(enums::BenderSuccess, enums::BenderFailure) : encounter_character;

  std::vector<Consequence> possible_consequences;

  for (const Consequence& consequence : current_encounter_.consequences_)
    if (consequence.consequence_source_ == source) possible_consequences.push_back(consequence);

  if (possible_consequences.empty()) return;

  int randomIndex = random_helper_.GenerateRandomInt(0, possible_consequences.size() - 1);

  Consequence random_consequence = possible_consequences[randomIndex];
  AddEncounterLogRecord(random_consequence.description_);
}

void EncounterGenerator::ProcessConsequenceResult(const Consequence& consequence, SpaceshipStats& spaceship_stats) {
  switch (consequence.consequence_type_) {
    case enums::Geen:
      AddEncounterLogRecord("Er is niks gebeurd en je bent veilig weggekomen");
      break;
    case enums::Overwinningspunt:
      AddEncounterLogRecord("Je krijgt (" + std::to_string(consequence.amount_) + ") overwinningspunten");
      spaceship_stats.AppendWinningPoints(consequence.amount_);
      break;
    case enums::Reparatie:
      AddEncounterLogRecord("Je hebt geluk; al je schadepunten worden gerepareerd!");
      spaceship_stats.ResetDamagePoints();
      break;
    case enums::Schade:
      AddEncounterLogRecord("Je raakt in een gevecht!");
      // todo: implement fight
      break;
    default:
      break;
  }
}

enums::EncounterCharacter EncounterGenerator::GetRandomCharacter(enums::EncounterCharacter character_one,
                                                                 enums::EncounterCharacter character_two) {
  return random_helper_.GenerateRandomInt(0, 1) == 0 ? character_one : character_two;
}

const std::vector<std::string>& EncounterGenerator::GetLatestEncounterLog() const {
  return current_encounter_log;
}

void EncounterGenerator::CreateRandomEncounter() {
  current_encounter_log.clear();
  current_encounter_ = encounters_.at(random_helper_.GenerateRandomInt(0, encounters_.size()-1));
  AddEncounterLogRecord(current_encounter_.description_);
}

void EncounterGenerator::AddEncounterLogRecord(const std::string& content) {
  current_encounter_log.emplace_back(content);
}

}
