#include <iostream>
#include "ui.h"

using namespace game;

namespace interface {

Ui::Ui(const GameManager &game) : game_(game), view_object_factory_() {
}

void Ui::ShowScan() const {
  auto scan = game_.GetCurrentScan();

  std::cout << "Scan van universum:\n";

  for (const auto &row : scan) {
    for (const auto &col : row)
      std::cout << col.asteroid_amount << col.encounter_amount << col.planet_amount << "  ";

    std::cout << "\n\n";
  }

  std::cout << "Kies je sector (Rij + kolom. Voorbeeld: 01 = rij 0 sector 1):\n";
}

void Ui::ShowSector() const {
  auto sector = game_.GetCurrentSector();

  std::cout << "Huidige sector:\n";

  for (const auto &row : sector) {
    for (const auto &col : row) {
      auto view_object = view_object_factory_.GetObjectCharacter(col);
      if (view_object) view_object->Print();
    }

    std::cout << "\n";
  }
}

void Ui::ShowPackagePickupBlocked() const {
  ShowSector();
  std::cout << "Geen geschikte bestemming gevonden voor pakket.\n";
}

void Ui::ShowPackageInfo() const {
  auto shipment = game_.GetSpaceship().GetCargoInfo().shipment_;
  std::cout << "Je vervoert: " << shipment.content_description_ << "\n";
  std::cout << "Bestemming: " << shipment.destination_description_ << "\n";
  std::cout << "Vanuit sector: " << GetFormattedCoordsString(shipment.source_sector_) << "\n";
  std::cout << "Sector bestemming: " << GetFormattedCoordsString(shipment.destination_sector_) << "\n";
  std::cout << "Planeet bestemming: " << GetFormattedCoordsString(shipment.destination_planet_) << "\n";
}

std::string Ui::GetFormattedCoordsString(game::Coords coords) const {
  return "x: " + std::to_string(coords.pos_x_) + ", y: " + std::to_string(coords.pos_y_);
}

void Ui::ShowPackageDeliverySuccess() const {
  std::cout << "Pakket succesvol afgeleverd!\n";
}

void Ui::UpdateUi(enums::MainGameState state, enums::SubGameState sub_game_state) const {
  if (state == enums::MainGameState::Scanning) ShowScan();
  if (state == enums::MainGameState::Movement) ShowSector();
  if (state == enums::MainGameState::PackagePickupBlocked) ShowPackagePickupBlocked();

  if (sub_game_state == enums::SubGameState::ShowPackage) ShowPackageInfo();
  if (sub_game_state == enums::SubGameState::PackageDeliverySuccess) ShowPackageDeliverySuccess();
}

}