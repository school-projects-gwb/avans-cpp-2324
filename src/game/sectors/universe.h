#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_

#include <vector>
#include "game/scans/scan_object.h"
#include "sector.h"
#include "game/scans/scan_select_result.h"
#include "scans/scan_creator.h"

class Universe {
 public:
  Universe() = default;
  void SetSectors(const Grid<ScanObject>& scanData, const ScanSelectResult& pickResult);
  Sector& GetActiveSector() const;
 private:
  Grid<Sector> sectors_;
  Sector* active_sector_ = nullptr;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_
