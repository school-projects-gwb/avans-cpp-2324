#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_

#include <vector>
#include "game/scans/scan_object.h"
#include "sector.h"
#include "game/scans/scan_select_result.h"
#include "scans/scan_creator.h"
#include "spaceship/spaceship.h"
#include "package_destination_result.h"

namespace game {
  class Universe {
   public:
    Universe() = default;
    void SetSectors(const Grid<ScanObject> &scanData, const ScanSelectResult &pickResult);
    Sector& GetActiveSector() const;
    void MoveSpaceship(enums::Direction direction);
    void MoveObjects(Coords target_location);
    void SetSpaceship(SpaceShip& ship);
    PackageDestinationResult GetPackageDestinationInfo() const;
    bool TryRemoveCollidingObjects(const Coords &target_position, enums::SectorObjectType collision_type);
   private:
    Grid<Sector> sectors_;
    Sector* active_sector_ = nullptr;
    SpaceShip* space_ship_ = nullptr;
    void AttemptMoveSpaceshipToDifferentSector(enums::Direction direction);
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_
