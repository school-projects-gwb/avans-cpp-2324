#include "sector.h"
#include "helpers/random_helper.h"
#include "scans/scan_creator.h"

namespace Game {
  Sector::Sector(const ScanObject &scanData, size_t row, size_t col)
      : scan_data_(scanData), row_(row), col_(col), objects_(kGridSize, kGridSize) {
    for (auto &object : objects_)
      for (auto &column : object)
        column = SectorObjectType::Empty;
  }

  void Sector::GenerateObjects() {
    PlaceObjectsOfType(SectorObjectType::Asteroid, scan_data_.asteroid_amount);
    PlaceObjectsOfType(SectorObjectType::Planet, scan_data_.planet_amount);
    PlaceObjectsOfType(SectorObjectType::Encounter, scan_data_.encounter_amount);
  }

  void Sector::PlaceObjectsOfType(SectorObjectType type, int amount) {
    for (int i = 0; i < amount; i++) {
      Coords coords = GetRandomFreeCoords();
      objects_[coords] = type;
    }
  }

  Grid<SectorObjectType> Sector::GetSectorObjects() const {
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

  bool Sector::IsPositionAvailable(Coords coords) {
    return objects_[coords] == SectorObjectType::Empty;
  }
}