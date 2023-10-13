#include <iostream>
#include "command_center.h"
#include "data/direction.h"

namespace Game {
  CommandCenter::CommandCenter() : scanner_(), universe_(), space_ship_() {
    scanner_.CreateScan();
  }

  void CommandCenter::ResetGame() {
    state_ = GameState::ShouldReset;
  }

  void CommandCenter::MovePlayer(Direction direction) {
    universe_.MoveSpaceship(space_ship_, direction);
    universe_.MoveObjects(space_ship_.GetPosition());
    if (space_ship_.IsAtUniverseEdge()) state_ = GameState::PendingReset;
  }

  GameState CommandCenter::GetState() const {
    return state_;
  }

  void CommandCenter::ProcessPlayerInput(int userInput) {
    if (state_ != GameState::Scanning) return;

    auto sector_input_result = scanner_.PickSectorByInput(userInput);
    if (!sector_input_result.is_valid_) return;

    universe_.SetSectors(scanner_.GetCurrentScan(), sector_input_result);

    auto free_coords = universe_.GetActiveSector().GetRandomFreeCoords();
    auto neighbor_objects = universe_.GetActiveSector().GetNeighborObjects(free_coords);
    space_ship_.SetPosition(free_coords, neighbor_objects);

    state_ = GameState::Movement;
  }

  Grid<ScanObject> CommandCenter::GetCurrentScan() const {
    return scanner_.GetCurrentScan();
  }

  const SpaceShip& CommandCenter::GetSpaceship() const {
    return space_ship_;
  }

  Grid<SectorObjectType> CommandCenter::GetCurrentSector() const {
    auto sector_objects = universe_.GetActiveSector().GetSectorObjects();
    auto spaceship_position = space_ship_.GetPosition();
    sector_objects[spaceship_position] = SectorObjectType::Spaceship;

    return sector_objects;
  }
}
