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
        column = enums::SectorObjectType::EmptySpace;
  }

  void Sector::GenerateObjects() {
    PlaceObjectsOfType(enums::SectorObjectType::Asteroid, scan_data_.asteroid_amount);
    PlaceObjectsOfType(enums::SectorObjectType::Planet, scan_data_.planet_amount);
    PlaceObjectsOfType(enums::SectorObjectType::Encounter, scan_data_.encounter_amount);
    is_generated_ = true;
  }

  void Sector::MoveObjects(const enums::SectorObjectType& object_type, const Coords& target_location) {
    std::vector<Coords> objectsToMove;

    for (int x = 0; x < objects_.GetColCount(); ++x)
      for (int y = 0; y < objects_.GetRowCount(); ++y) {
        Coords current_position{x, y};
        if (objects_[current_position] == object_type) objectsToMove.push_back(current_position);
      }

    for (const Coords& current_position : objectsToMove) {
      Coords next_position = current_position;
      if (current_position.pos_x < target_location.pos_x) {
        next_position.pos_x++;
      } else if (current_position.pos_x > target_location.pos_x) {
        next_position.pos_x--;
      } else if (current_position.pos_y < target_location.pos_y) {
        next_position.pos_y++;
      } else if (current_position.pos_y > target_location.pos_y) {
        next_position.pos_y--;
      }

      if (IsPositionInSectorBounds(next_position) && IsEmptyNewPosition(next_position)) {
        objects_[current_position] = enums::SectorObjectType::EmptySpace;
        objects_[next_position] = object_type;
      }
    }
  }

  void Sector::SetObjectAtPosition(enums::SectorObjectType type, Coords target_position) {
    objects_[target_position] = type;
  }

  void Sector::MoveObjectAtPositionToTargetPosition(const Coords& current_position, const Coords& target_position) {
    if (IsEmptyNewPosition(current_position)) return;
    objects_[target_position] = objects_[current_position];
    objects_[current_position] = enums::SectorObjectType::EmptySpace;
  }

  void Sector::PlaceObjectsOfType(enums::SectorObjectType type, int amount) {
    for (int i = 0; i < amount; i++) {
      Coords coords = GetRandomFreeCoords();
      objects_[coords] = type;
    }
  }

  const Grid<enums::SectorObjectType>& Sector::GetSectorObjects() const {
    return objects_;
  }

  Coords Sector::GetRandomFreeCoords() const {
    RandomHelper random_helper = RandomHelper::GetInstance();
    Coords coords = {};

    do {
      coords.pos_x = random_helper.GenerateRandomInt(0, kGridSize - 1);
      coords.pos_y = random_helper.GenerateRandomInt(0, kGridSize - 1);
    } while (objects_[coords] != enums::SectorObjectType::EmptySpace);

    return coords;
  }

  bool Sector::IsEmptyNewPosition(Coords coords) const {
    return IsPositionInSectorBounds(coords) && objects_[coords] == enums::SectorObjectType::EmptySpace;
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
      neighborCoords.pos_x +=  + offset.pos_x;
      neighborCoords.pos_y +=  + offset.pos_y;

      if (IsPositionInSectorBounds(neighborCoords)) {
        SpaceshipNeighborObject neighborObject = {};
        neighborObject.coords = neighborCoords;
        neighborObject.object_type = objects_[neighborCoords];
        neighbors.push_back(neighborObject);
      }
    }

    return neighbors;
  }

  bool Sector::IsPositionInSectorBounds(Coords coords) const {
    return (coords.pos_x >= 0 && coords.pos_x < objects_.GetColCount()
        && coords.pos_y >= 0 && coords.pos_y < objects_.GetRowCount());
  }

  Coords Sector::GetRelativeNeighborSectorCoords(Coords coords, enums::Direction direction) const {
    Coords new_coords = coords;
    int col_count_check = objects_.GetColCount()-1;
    int row_count_check = objects_.GetRowCount()-1;

    if (direction == enums::Left || direction == enums::Right) {
      new_coords.pos_x = coords.pos_x <= 0 ? col_count_check : 0;
    } else {
      new_coords.pos_y = coords.pos_y <= 0 ? row_count_check : 0;
    }

    return new_coords;
  }

  bool Sector::AreObjectsGenerated() const {
    return is_generated_;
  }

  Sector* Sector::GetNeighboringSector(enums::Direction direction) const {
    switch (direction) {
      case enums::Up:
        return kUp;
      case enums::Down:
        return kDown;
      case enums::Left:
        return kLeft;
      case enums::Right:
        return kRight;
      default:
        return nullptr;
    }
  }

  const Coords& Sector::GetPositionInUniverse() const {
    return position_in_universe_;
  }

  bool Sector::HasObjectOfType(enums::SectorObjectType object_type) const {
    if (!AreObjectsGenerated()) return false;

    for (int x = 0; x < objects_.GetColCount(); ++x)
      for (int y = 0; y < objects_.GetRowCount(); ++y) {
        Coords current_position{x, y};
        if (objects_[current_position] == object_type) return true;
      }

    return false;
  }

  Coords Sector::GetRandomObjectPosition(enums::SectorObjectType object_type) const {
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