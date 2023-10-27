#include <iostream>
#include "universe.h"
#include "scans/scan_creator.h"
#include "package_destination_result.h"

namespace game {
  void Universe::SetSectors(const Grid<ScanObject> &scanData, const ScanSelectResult &pickResult) {
    size_t numRows = scanData.GetRowCount();
    size_t numCols = scanData.GetColCount();

    sectors_.Resize(numRows, numCols, Sector(ScanObject{}, Coords{}));

    for (int row = 0; row < numRows; row++)
      for (int col = 0; col < numCols; col++) {
        Coords universe_coords = {col, row};
        sectors_(row, col) = Sector(scanData(row, col), universe_coords);
      }

    for (int row = 0; row < numRows; row++) {
      for (int col = 0; col < numCols; col++) {
        Sector &current_sector = sectors_(row, col);

        current_sector.kUp = (row > 0) ? &sectors_(row - 1, col) : nullptr;
        current_sector.kDown = (row < numRows - 1) ? &sectors_(row + 1, col) : nullptr;
        current_sector.kLeft = (col > 0) ? &sectors_(row, col - 1) : nullptr;
        current_sector.kRight = (col < numCols - 1) ? &sectors_(row, col + 1) : nullptr;
      }
    }

    active_sector_ = &sectors_(pickResult.row_number, pickResult.col_number);
    active_sector_->GenerateObjects();
  }

  void Universe::MoveObjects(const Coords& target_location) {
    active_sector_->MoveObjects(enums::SectorObjectType::Encounter, target_location);
  }

  void Universe::MoveSpaceship(const enums::Direction& direction) {
    auto next_position = space_ship_->GetNextMovementPosition(direction);
    auto position_available = active_sector_->IsEmptyNewPosition(next_position);

    if (position_available) {
      auto neighbor_objects = active_sector_->GetNeighborObjects(next_position);
      active_sector_->MoveObjectAtPositionToTargetPosition(space_ship_->GetPosition(), next_position);
      space_ship_->SetPosition(next_position, active_sector_->GetPositionInUniverse(), neighbor_objects);
      space_ship_->SetIsAtUniverseEdge(false);
    } else if (!active_sector_->IsPositionInSectorBounds(next_position)) {
      AttemptMoveSpaceshipToDifferentSector(direction);
    }
  }

  void Universe::AttemptMoveSpaceshipToDifferentSector(const enums::Direction& direction) {
    auto neighboring_sector = active_sector_->GetNeighboringSector(direction);
    if (neighboring_sector == nullptr) {
      space_ship_->SetIsAtUniverseEdge(true);
      return;
    }

    auto next_position_sector_neighbor = active_sector_->GetRelativeNeighborSectorCoords(space_ship_->GetPosition(), direction);

    if (!neighboring_sector->AreObjectsGenerated()) neighboring_sector->GenerateObjects();
    auto new_sector_position_available = neighboring_sector->IsEmptyNewPosition(next_position_sector_neighbor);
    if (!new_sector_position_available) return;

    active_sector_->SetObjectAtPosition(enums::SectorObjectType::EmptySpace, space_ship_->GetPosition());
    active_sector_ = neighboring_sector;
    auto neighbor_objects = active_sector_->GetNeighborObjects(next_position_sector_neighbor);

    active_sector_->SetObjectAtPosition(enums::SectorObjectType::Spaceship, next_position_sector_neighbor);
    space_ship_->SetPosition(next_position_sector_neighbor, active_sector_->GetPositionInUniverse(), neighbor_objects);
  }

  const Sector& Universe::GetActiveSector() const {
    return *active_sector_;
  }

  void Universe::SetSpaceship(SpaceShip& space_ship) {
    space_ship_ = &space_ship;
    auto free_coords = active_sector_->GetRandomFreeCoords();
    auto neighbor_objects = active_sector_->GetNeighborObjects(free_coords);
    space_ship_->SetPosition(free_coords, active_sector_->GetPositionInUniverse(), neighbor_objects);
    active_sector_->SetObjectAtPosition(enums::SectorObjectType::Spaceship, free_coords);
  }

  PackageDestinationResult Universe::GetPackageDestinationInfo() const {
    const int minimum_distance = 0;
    PackageDestinationResult result{};

    for (size_t row = 0; row < sectors_.GetRowCount(); row++) {
      for (size_t col = 0; col < sectors_.GetColCount(); col++) {
        Coords current_sector_position = sectors_(row, col).GetPositionInUniverse();
        Coords active_sector_position = active_sector_->GetPositionInUniverse();
        size_t row_distance = std::abs(static_cast<int>(current_sector_position.pos_x - active_sector_position.pos_x));
        size_t col_distance = std::abs(static_cast<int>(current_sector_position.pos_y - active_sector_position.pos_y));

        if ((row_distance < minimum_distance && col_distance < minimum_distance)
        || !sectors_(row, col).HasObjectOfType(enums::SectorObjectType::Planet)) continue;

        result.destination_planet_coords = sectors_(row, col).GetRandomObjectPosition(enums::SectorObjectType::Planet);
        result.destination_sector_coords = current_sector_position;
        result.current_sector_coords = active_sector_position;
        result.has_valid_destination = true;
        break;
      }
    }

    return result;
  }

  bool Universe::TryRemoveCollidingObjects(const Coords &target_position, enums::SectorObjectType collision_type) {
    auto neighbor_objects = active_sector_->GetNeighborObjects(target_position);

    bool removedAtLeastOne = false;
    for (const auto& neighbor : neighbor_objects) {
      if (neighbor.object_type != collision_type) continue;

      active_sector_->SetObjectAtPosition(enums::SectorObjectType::EmptySpace, neighbor.coords);
      removedAtLeastOne = true;
      }

    return removedAtLeastOne;
  }
}
