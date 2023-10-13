#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_

#include <vector>
#include "game/scans/scan_object.h"
#include "sector.h"
#include "game/scans/scan_select_result.h"
#include "scans/scan_creator.h"
#include "spaceship/spaceship.h"

namespace Game {
  class Universe {
   public:
    Universe() = default;
    void SetSectors(const Grid<ScanObject> &scanData, const ScanSelectResult &pickResult);
    Sector &GetActiveSector() const;
    void MoveSpaceship(SpaceShip& space_ship, Direction direction);
    void MoveObjects(Coords target_location);
   private:
    Grid<Sector> sectors_;
    Sector* active_sector_ = nullptr;
    void AttemptMoveSpaceshipToDifferentSector(SpaceShip& space_ship, Direction direction);
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_
