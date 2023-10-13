#include <iostream>
#include "sector.h"
#include "helpers/random_helper.h"
#include "scans/scan_creator.h"

namespace Game {
  Sector::Sector(const ScanObject &scanData)
      : scan_data_(scanData), objects_(kGridSize, kGridSize) {
    for (auto &object : objects_)
      for (auto &column : object)
        column = SectorObjectType::Empty;
  }

  void Sector::GenerateObjects() {
    PlaceObjectsOfType(SectorObjectType::Asteroid, scan_data_.asteroid_amount);
    PlaceObjectsOfType(SectorObjectType::Planet, scan_data_.planet_amount);
    PlaceObjectsOfType(SectorObjectType::Encounter, scan_data_.encounter_amount);
    is_generated_ = true;
  }

  void Sector::MoveObjects(SectorObjectType object_type, Coords target_location) {
    for (int x = 0; x < objects_.GetColCount(); ++x) {
      for (int y = 0; y < objects_.GetRowCount(); ++y) {
        Coords current_position{x, y};
        if (objects_[current_position] != object_type) continue;

        Coords next_position = current_position;

        if (current_position.pos_x_ < target_location.pos_x_) {
          next_position.pos_x_++;
        } else if (current_position.pos_x_ > target_location.pos_x_) {
          next_position.pos_x_--;
        } else if (current_position.pos_y_ < target_location.pos_y_) {
          next_position.pos_y_++;
        } else if (current_position.pos_y_ > target_location.pos_y_) {
          next_position.pos_y_--;
        }

        if (IsPositionInSectorBounds(next_position) && IsEmptyNewPosition(next_position)) {
          if (next_position == target_location) return;
          objects_[current_position] = SectorObjectType::Empty;
          objects_[next_position] = object_type;
        }
      }
    }
  }

  void Sector::PlaceObjectsOfType(SectorObjectType type, int amount) {
    for (int i = 0; i < amount; i++) {
      Coords coords = GetRandomFreeCoords();
      objects_[coords] = type;
    }
  }

  const Grid<SectorObjectType>& Sector::GetSectorObjects() const {
    return objects_;
  }

  Coords Sector::GetRandomFreeCoords() const {
    RandomHelper random_helper = RandomHelper::GetInstance();
    Coords coords = {};

    do {
      coords.pos_x_ = random_helper.GenerateRandomInt(0, kGridSize - 1);
      coords.pos_y_ = random_helper.GenerateRandomInt(0, kGridSize - 1);
    } while (objects_[coords] != SectorObjectType::Empty);

    return coords;
  }

  bool Sector::IsEmptyNewPosition(Coords coords) const {
    return IsPositionInSectorBounds(coords) && objects_[coords] == SectorObjectType::Empty;
  }

  std::vector<SectorObjectType> Sector::GetNeighborObjects(Coords coords) const {
    std::vector<SectorObjectType> neighbors;

    const Coords offsets[] = {
        {0, -1}, // Above
        {0, 1},  // Below
        {-1, 0}, // Left
        {1, 0}   // Right
    };

    for (const Coords& offset : offsets) {
      Coords neighborCoords = coords;
      neighborCoords.pos_x_ +=  + offset.pos_x_;
      neighborCoords.pos_y_ +=  + offset.pos_y_;

      if (IsPositionInSectorBounds(neighborCoords)) {
        SectorObjectType neighborObject = objects_[neighborCoords];
        neighbors.push_back(neighborObject);
      }
    }

    return neighbors;
  }

  bool Sector::IsPositionInSectorBounds(Coords coords) const {
    return (coords.pos_x_ >= 0 && coords.pos_x_ < objects_.GetColCount()
        && coords.pos_y_ >= 0 && coords.pos_y_ < objects_.GetRowCount());
  }

  Coords Sector::GetRelativeNeighborSectorCoords(Coords coords, Direction direction) const {
    Coords new_coords = coords;
    int col_count_check = objects_.GetColCount()-1;
    int row_count_check = objects_.GetRowCount()-1;

    if (direction == Left || direction == Right) {
      new_coords.pos_x_ = coords.pos_x_ <= 0 ? col_count_check : 0;
    } else {
      new_coords.pos_y_ = coords.pos_y_ <= 0 ? row_count_check : 0;
    }

    return new_coords;
  }

  bool Sector::AreObjectsGenerated() const {
    return is_generated_;
  }

  Sector* Sector::GetNeighboringSector(Direction direction) const {
    switch (direction) {
      case Up:
        return kUp;
      case Down:
        return kDown;
      case Left:
        return kLeft;
      case Right:
        return kRight;
      default:
        return nullptr;
    }
  }
}