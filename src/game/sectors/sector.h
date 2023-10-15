#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_

#include <vector>
#include "game/scans/scan_object.h"
#include "sector_object.h"
#include "data/grid.h"
#include "data/coords.h"
#include "data/direction.h"
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

    const Grid<SectorObjectType>& GetSectorObjects() const;
    Coords GetRandomFreeCoords() const;
    std::vector<SpaceshipNeighborObject> GetNeighborObjects(Coords coords) const;
    Coords GetRelativeNeighborSectorCoords(Coords coords, Direction direction) const;
    Coords GetPositionInUniverse() const;
    Sector* GetNeighboringSector(game::Direction direction) const;
    Coords GetRandomObjectPosition(SectorObjectType object_type);

    bool IsEmptyNewPosition(Coords coords) const;
    bool IsPositionInSectorBounds(Coords coords) const;
    bool HasObjectOfType(SectorObjectType object_type) const;
    bool AreObjectsGenerated() const;
    void MoveObjects(SectorObjectType object_type, Coords target_location);
    void MoveObjectAtPositionToTargetPosition(Coords current_position, Coords target_position);
    void SetObjectAtPosition(SectorObjectType type, Coords target_position);
   private:
    Coords position_in_universe_;
    bool is_generated_ = false;
    ScanObject scan_data_;
    static const int kGridSize = 10;
    Grid<SectorObjectType> objects_;

    void PlaceObjectsOfType(SectorObjectType type, int amount);
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
