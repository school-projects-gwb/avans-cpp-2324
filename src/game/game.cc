#include "game.h"

Game::Game() : scanner_(), sector_manager_() {
  scanner_.CreateScan();
}

void Game::HandlePlayerMovement(int direction) {

}

GameState Game::GetState() const {
  return state_;
}

void Game::HandlePlayerInputValue(int userInput) {
  if (state_ == Scanning) {
    auto result = scanner_.PickSectorByInput(userInput);
    auto sectors = scanner_.GetCurrentScan();
    if (result.is_valid_) sector_manager_.SetSectors(sectors, result);
  }
}

std::vector<std::vector<ScanObject>> Game::GetCurrentScan() const {
  return scanner_.GetCurrentScan();
}
