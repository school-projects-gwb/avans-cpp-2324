#include <iostream>
#include "universe.h"
#include "scans/scan_creator.h"

namespace Game {
  void Universe::SetSectors(const Grid<ScanObject> &scanData, const ScanSelectResult &pickResult) {
    size_t numRows = scanData.GetRowCount();
    size_t numCols = scanData.GetColCount();

    sectors_.Resize(numRows, numCols, Sector(ScanObject{}));

    for (size_t row = 0; row < numRows; row++)
      for (size_t col = 0; col < numCols; col++)
        sectors_(row, col) = Sector(scanData(row, col));

    for (size_t row = 0; row < numRows; row++) {
      for (size_t col = 0; col < numCols; col++) {
        Sector &current_sector = sectors_(row, col);

        current_sector.kUp = (row > 0) ? &sectors_(row - 1, col) : nullptr;
        current_sector.kDown = (row < numRows - 1) ? &sectors_(row + 1, col) : nullptr;
        current_sector.kLeft = (col > 0) ? &sectors_(row, col - 1) : nullptr;
        current_sector.kRight = (col < numCols - 1) ? &sectors_(row, col + 1) : nullptr;
      }
    }

    active_sector_ = &sectors_(pickResult.row_number_, pickResult.col_number_);
    active_sector_->GenerateObjects();
  }

  void Universe::MoveObjects(Coords target_location) {
    active_sector_->MoveObjects(SectorObjectType::Encounter, target_location);
  }

  void Universe::MoveSpaceship(SpaceShip& space_ship, Direction direction) {
    auto next_position = space_ship.GetNextMovementPosition(direction);
    auto position_available = active_sector_->IsEmptyNewPosition(next_position);

    if (position_available) {
      auto neighbor_objects = active_sector_->GetNeighborObjects(next_position);
      space_ship.SetPosition(next_position, neighbor_objects);
      space_ship.SetIsAtUniverseEdge(false);
    } else if (!active_sector_->IsPositionInSectorBounds(next_position)) {
      AttemptMoveSpaceshipToDifferentSector(space_ship, direction);
    }
  }

  void Universe::AttemptMoveSpaceshipToDifferentSector(SpaceShip& space_ship, Direction direction) {
    auto neighboring_sector = active_sector_->GetNeighboringSector(direction);
    if (neighboring_sector == nullptr) {
      space_ship.SetIsAtUniverseEdge(true);
      return;
    }

    auto next_position_sector_neighbor = active_sector_->GetRelativeNeighborSectorCoords(space_ship.GetPosition(), direction);

    if (!neighboring_sector->AreObjectsGenerated()) neighboring_sector->GenerateObjects();
    auto new_sector_position_available = neighboring_sector->IsEmptyNewPosition(next_position_sector_neighbor);
    if (!new_sector_position_available) return;
    active_sector_ = neighboring_sector;
    auto neighbor_objects = active_sector_->GetNeighborObjects(next_position_sector_neighbor);
    space_ship.SetPosition(next_position_sector_neighbor, neighbor_objects);
  }

  Sector &Universe::GetActiveSector() const {
    return *active_sector_;
  }
}
