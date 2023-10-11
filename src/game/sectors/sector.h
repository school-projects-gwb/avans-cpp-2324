#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_

#include <vector>
#include "game/scans/scan_object.h"
#include "sector_object.h"
#include "data/grid.h"
#include "data/coords.h"
#include "data/direction.h"
#include "spaceship/spaceship.h"

namespace Game {
  class Sector {
   public:
    Sector(const ScanObject &scanData);

    void GenerateObjects();

    Sector *kUp = nullptr;
    Sector *kDown = nullptr;
    Sector *kLeft = nullptr;
    Sector *kRight = nullptr;

    const Grid<SectorObjectType>& GetSectorObjects() const;
    Coords GetRandomFreeCoords() const;
    std::vector<SectorObjectType> GetNeighborObjects(Coords coords) const;
    Coords GetRelativeNeighborSectorCoords(Coords coords, Direction direction) const;
    Sector* GetNeighboringSector(Game::Direction direction) const;

    bool IsEmptyNewPosition(Coords coords) const;
    bool IsPositionInSectorBounds(Coords coords) const;
    bool AreObjectsGenerated() const;
   private:
    bool is_generated_ = false;
    ScanObject scan_data_;
    static const int kGridSize = 10;
    Grid<SectorObjectType> objects_;

    void PlaceObjectsOfType(SectorObjectType type, int amount);
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
