#include <iostream>
#include "sector.h"
#include "helpers/random_helper.h"
#include "scans/scan_creator.h"
#include "spaceship/spaceship_neighbor_object.h"

namespace game {
  Sector::Sector(const ScanObject &scanData, Coords universe_position)
      : scan_data_(scanData), objects_(kGridSize, kGridSize), position_in_universe_(universe_position) {
    for (auto &object : objects_)
      for (auto &column : object)
        column = SectorObjectType::EmptySpace;
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
          objects_[current_position] = SectorObjectType::EmptySpace;
          objects_[next_position] = object_type;
        }
      }
    }
  }

  void Sector::SetObjectAtPosition(SectorObjectType type, Coords target_position) {
    if (IsEmptyNewPosition(target_position)) objects_[target_position] = type;
  }

  void Sector::MoveObjectAtPositionToTargetPosition(Coords current_position, Coords target_position) {
    if (IsEmptyNewPosition(current_position)) return;
    objects_[target_position] = objects_[current_position];
    objects_[current_position] = SectorObjectType::EmptySpace;
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
    } while (objects_[coords] != SectorObjectType::EmptySpace);

    return coords;
  }

  bool Sector::IsEmptyNewPosition(Coords coords) const {
    return IsPositionInSectorBounds(coords) && objects_[coords] == SectorObjectType::EmptySpace;
  }

  std::vector<SpaceshipNeighborObject> Sector::GetNeighborObjects(Coords coords) const {
    std::vector<SpaceshipNeighborObject> neighbors;

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
        SpaceshipNeighborObject neighborObject = {};
        neighborObject.coords_ = neighborCoords;
        neighborObject.object_type_ = objects_[neighborCoords];
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

  Coords Sector::GetPositionInUniverse() const {
    return position_in_universe_;
  }

  bool Sector::HasObjectOfType(SectorObjectType object_type) const {
    if (!AreObjectsGenerated()) return false;

    for (int x = 0; x < objects_.GetColCount(); ++x)
      for (int y = 0; y < objects_.GetRowCount(); ++y) {
        Coords current_position{x, y};
        if (objects_[current_position] != object_type) return true;
      }

    return false;
  }

  Coords Sector::GetRandomObjectPosition(SectorObjectType object_type) {
    std::vector<Coords> candidates{};

    for (int x = 0; x < objects_.GetColCount(); ++x)
      for (int y = 0; y < objects_.GetRowCount(); ++y) {
        Coords current_position{x, y};
        if (objects_[current_position] == object_type) candidates.push_back(current_position);
      }

    if ((candidates.empty())) return {};

    int randomIndex = RandomHelper::GetInstance().GenerateRandomInt(0, candidates.size() - 1);
    return candidates[randomIndex];
  }
}