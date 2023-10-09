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
  if (state_ == GameState::Scanning) {
    auto sector_input_result = scanner_.PickSectorByInput(userInput);
    if (!sector_input_result.is_valid_) return;

    auto sector_scan = scanner_.GetCurrentScan();
    universe_.SetSectors(sector_scan, sector_input_result);
    state_ = GameState::Movement;
  }
}

Grid<ScanObject> Game::GetCurrentScan() const {
  return scanner_.GetCurrentScan();
}

Grid<SectorObjectType> Game::GetCurrentSector() const {
  return universe_.GetActiveSector().GetSectorObjects();
}
