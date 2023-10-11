#include <iostream>
#include "ui.h"

using namespace Game;

namespace Interface {
  Ui::Ui(const CommandCenter &game) : game_(game), view_object_factory_() {
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
      for (const auto &col : row) {
        auto view_object = view_object_factory_.GetObjectCharacter(col);
        if (view_object) view_object->Print();
      }

      std::cout << "\n";
    }
  }

  void Ui::UpdateUi(GameState state) const {
    if (state == GameState::Scanning) ShowScan();
    if (state == GameState::Movement) ShowSector();
  }
}