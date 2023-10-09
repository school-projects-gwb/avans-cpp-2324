#include <iostream>
#include "game.h"

Game::Game() : scanner_(), universe_() {
  scanner_.CreateScan();
}

void Game::MovePlayer(int direction) {

}

GameState Game::GetState() const {
  return state_;
}

void Game::ProcessPlayerInput(int userInput) {
  if (state_ == Scanning) {
    auto result = scanner_.PickSectorByInput(userInput);
    auto sectors = scanner_.GetCurrentScan();
    if (result.is_valid_) {
      universe_.SetSectors(sectors, result);
      auto& x = universe_.GetActiveSector();
      auto objects = x.GetSectorObjects();

      for (const auto &row : objects) {
        for (const auto &col : row)
          std::cout << col << "  ";
        std::cout << "\n";
      }
    }
  }
}

Grid<ScanObject> Game::GetCurrentScan() const {
  return scanner_.GetCurrentScan();
}
