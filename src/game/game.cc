#include "game.h"

Game::Game() : scanner_(), sector_manager_() {
  scanner_.Scan();
}

void Game::HandlePlayerMovement(int direction) {

}

GameState Game::GetState() const {
  return state_;
}

void Game::HandlePlayerInputValue(int userInput) {
  if (state_ == Scan) {
    auto result = scanner_.PickSectorByInput(userInput);
    auto sectors = scanner_.GetCurrentScan();
    if (result.is_valid_) sector_manager_.SetSectors(sectors, result);
  }
}

std::vector<std::vector<ScanObject>> Game::GetCurrentScan() const {
  return scanner_.GetCurrentScan();
}
