#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_

#include "entities/scan_object.h"
class Sector {
 public:
  Sector(const ScanObject& scanData, size_t row, size_t col);

  int GetAsteroidAmount() const;
  int GetPlanetAmount() const;
  int GetEncounterAmount() const;

  int GetRow() const;
  int GetCol() const;

 private:
  ScanObject scan_data_;
  int row_;
  int col_;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
