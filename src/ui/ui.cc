#include <iostream>
#include "ui.h"

Ui::Ui(const Game& game) : game_(game) {
}

void Ui::ShowScan() const {
  auto scan = game_.GetCurrentScan();

  std::cout << "CreateScan van universum:\n";

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
    for (const auto &col : row)
      std::cout << col << " ";

    std::cout << "\n";
  }
}

void Ui::UpdateUi(GameState state) const {
  if (state == GameState::Scanning) ShowScan();
  if (state == GameState::Movement) ShowSector();
}
