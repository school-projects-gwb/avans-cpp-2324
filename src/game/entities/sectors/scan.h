#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_

#include <vector>
#include "entities/scan_object.h"
#include "sector.h"
#include "entities/scan_select_result.h"

class Scan {
 public:
  Scan() = default;
  void SetSectors(const std::vector<std::vector<ScanObject>>& scanData, const ScanSelectResult& pickResult);
 private:
  std::vector<std::vector<Sector>> sectors_;
  Sector* active_sector_;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SECTOR_MANAGER_H_
