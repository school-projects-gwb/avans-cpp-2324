#include <iostream>
#include "ui.h"
#include "logger.h"

using namespace game;

namespace interface {

Ui::Ui(const GameManager &game) : game_(game), view_object_factory_() {
}

void Ui::ShowScan() const {
  auto scan = game_.GetCurrentScan();

  PrintToOutput("Scan van universum:\n");

  for (const auto &row : scan) {
    for (const auto &col : row)
      PrintToOutput(std::to_string(col.asteroid_amount) + std::to_string(col.encounter_amount) +
      std::to_string(col.planet_amount) + "  ");

    PrintToOutput("\n\n");
  }

  PrintToOutput("Kies je sector (Rij + kolom. Voorbeeld: 01 = rij 0 sector 1):\n");
}

void Ui::ShowSector() const {
  auto sector = game_.GetCurrentSector();
  auto sector_coords = game_.GetCurrentSectorCoords();

  PrintToOutput("Huidige sector (positie " + GetFormattedCoordsString(sector_coords) + ")\n");

  for (const auto &row : sector) {
    for (const auto &col : row) {
      auto view_object = view_object_factory_.GetObjectCharacter(col);
      if (view_object) PrintToOutput(view_object->GetPrintContent());
    }

    PrintToOutput("\n");
  }
}

void Ui::PrintToOutput(const std::string& content) {
  std::cout << content;
  persistence::Logger::GetInstance().AppendLogRecord(content);
}

void Ui::ShowPackageInfo() const {
  auto shipment = game_.GetSpaceship().GetCargoInfo().shipment;
  PrintToOutput("Je vervoert: " + shipment.content_description + "\n");
  PrintToOutput("Bestemming: " + shipment.destination_description + "\n");
  PrintToOutput("Vanuit sector: " + GetFormattedCoordsString(shipment.source_sector) + "\n");
  PrintToOutput("Sector bestemming: " + GetFormattedCoordsString(shipment.destination_sector) + "\n");
  PrintToOutput("Planeet bestemming: " + GetFormattedCoordsString(shipment.destination_planet) + "\n");
}

std::string Ui::GetFormattedCoordsString(game::Coords coords) {
  return "x: " + std::to_string(coords.pos_x+1) + ", y: " + std::to_string(coords.pos_y+1);
}

void Ui::ShowEncounter() const {
  PrintToOutput("\n");

  auto encounter_log = game_.GetEncounterLog();
  for (const auto& record : encounter_log)
    PrintToOutput(record + "\n");

  PrintToOutput("\n");
}

void Ui::UpdateUi(enums::MainGameState state, enums::SubGameState sub_game_state) const {
  if (sub_game_state == enums::SubGameState::ShowPackage) ShowPackageInfo();
  if (sub_game_state == enums::SubGameState::ShowEncounter) ShowEncounter();
  if (sub_game_state == enums::SubGameState::PackagePickupBlocked) PrintToOutput("Geen geschikte bestemming gevonden voor pakket.\n");
  if (sub_game_state == enums::SubGameState::PackageDeliverySuccess) {
    auto space_ship = game_.GetSpaceship();
    PrintToOutput("Pakket succesvol afgeleverd! Je hebt " + std::to_string(space_ship.GetWinningPoints()) + " punt(en).\n");
  }

  if (state == enums::MainGameState::Scanning) ShowScan();
  if (state == enums::MainGameState::Movement) ShowSector();
  if (state == enums::MainGameState::ActiveEncounter) ShowEncounter();

  if (state == enums::MainGameState::PendingReset) PrintToOutput("Rand van universum bereikt! Wil je opgeven?\n");
  if (state == enums::MainGameState::HasWon) PrintToOutput("Je hebt gewonnen! Je kan opnieuw spelen of stoppen.\n");
  if (state == enums::MainGameState::HasLost) PrintToOutput("Je hebt verloren! Je kan opnieuw spelen of stoppen.?\n");
}

}