#include <iostream>
#include "game_manager.h"
#include "data/direction.h"

namespace game {
  GameManager::GameManager() : scanner_(), universe_(), space_ship_() {
    scanner_.CreateScan();
  }

  void GameManager::ResetGame() {
    state_ = GameState::ShouldReset;
  }

  void GameManager::MovePlayer(Direction direction) {
    universe_.MoveSpaceship(direction);
    universe_.MoveObjects(space_ship_.GetPosition());
    if (space_ship_.IsAtUniverseEdge()) state_ = GameState::PendingReset;
  }

  GameState GameManager::GetState() const {
    return state_;
  }

  void GameManager::ProcessPlayerInput(int userInput) {
    if (state_ != GameState::Scanning) return;

    auto sector_input_result = scanner_.PickSectorByInput(userInput);
    if (!sector_input_result.is_valid_) return;

    universe_.SetSectors(scanner_.GetCurrentScan(), sector_input_result);
    universe_.SetSpaceship(space_ship_);

    state_ = GameState::Movement;
  }

  Grid<ScanObject> GameManager::GetCurrentScan() const {
    return scanner_.GetCurrentScan();
  }

  const SpaceShip& GameManager::GetSpaceship() const {
    return space_ship_;
  }

  Grid<SectorObjectType> GameManager::GetCurrentSector() const {
    return universe_.GetActiveSector().GetSectorObjects();
  }
}
