#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_

#include <vector>
#include "game/scans/scan_object.h"
#include "data_types/grid.h"
#include "data_types/coords.h"
#include "game/enums/direction.h"
#include "spaceship/spaceship.h"
#include "spaceship/spaceship_neighbor_object.h"

namespace game {

class Sector {
 public:
  Sector(const ScanObject &scanData, Coords universe_position);

  void GenerateObjects();

  Sector *kUp = nullptr;
  Sector *kDown = nullptr;
  Sector *kLeft = nullptr;
  Sector *kRight = nullptr;

  [[nodiscard]] const Grid<enums::SectorObjectType>& GetSectorObjects() const;
  [[nodiscard]] Coords GetRandomFreeCoords() const;
  [[nodiscard]] std::vector<SpaceshipNeighborObject> GetNeighborObjects(Coords coords) const;
  [[nodiscard]] Coords GetRelativeNeighborSectorCoords(Coords coords, enums::Direction direction) const;
  [[nodiscard]] const Coords& GetPositionInUniverse() const;
  [[nodiscard]] Sector* GetNeighboringSector(enums::Direction direction) const;
  [[nodiscard]] Coords GetRandomObjectPosition(enums::SectorObjectType object_type) const;

  [[nodiscard]] bool IsEmptyNewPosition(Coords coords) const;
  [[nodiscard]] bool IsPositionInSectorBounds(Coords coords) const;
  [[nodiscard]] bool HasObjectOfType(enums::SectorObjectType object_type) const;
  [[nodiscard]] bool AreObjectsGenerated() const;
  void MoveObjects(const enums::SectorObjectType& object_type, const Coords& target_location);
  void MoveObjectAtPositionToTargetPosition(const Coords& current_position, const Coords& target_position);
  void SetObjectAtPosition(enums::SectorObjectType type, Coords target_position);
 private:
  Coords position_in_universe_;
  bool is_generated_ = false;
  ScanObject scan_data_;
  static const int kGridSize = 10;
  Grid<enums::SectorObjectType> objects_;

  void PlaceObjectsOfType(enums::SectorObjectType type, int amount);
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
