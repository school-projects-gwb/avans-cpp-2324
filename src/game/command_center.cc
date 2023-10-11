#include <iostream>
#include "command_center.h"
#include "data/movement_direction.h"

namespace Game {
  CommandCenter::CommandCenter() : scanner_(), universe_(), space_ship_() {
    scanner_.CreateScan();
  }

  void CommandCenter::MovePlayer(MovementDirection direction) {
    auto next_position = space_ship_.GetNextMovementPosition(direction);
    auto position_available = universe_.GetActiveSector().IsPositionAvailable(next_position);
    if (position_available) space_ship_.SetPosition(next_position);
  }

  GameState CommandCenter::GetState() const {
    return state_;
  }

  void CommandCenter::ProcessPlayerInput(int userInput) {
    if (state_ == GameState::Scanning) {
      auto sector_input_result = scanner_.PickSectorByInput(userInput);
      if (!sector_input_result.is_valid_) return;

      auto sector_scan = scanner_.GetCurrentScan();
      std::cout << "FFF";
      universe_.SetSectors(sector_scan, sector_input_result);

      auto free_coords = universe_.GetActiveSector().GetRandomFreeCoords();
      space_ship_.SetPosition(free_coords);

      state_ = GameState::Movement;
    }
  }

  Grid<ScanObject> CommandCenter::GetCurrentScan() const {
    return scanner_.GetCurrentScan();
  }

  Grid<SectorObjectType> CommandCenter::GetCurrentSector() const {
    auto sector_objects = universe_.GetActiveSector().GetSectorObjects();
    auto spaceship_position = space_ship_.GetPosition();
    sector_objects[spaceship_position] = SectorObjectType::Spaceship;

    return sector_objects;
  }
}