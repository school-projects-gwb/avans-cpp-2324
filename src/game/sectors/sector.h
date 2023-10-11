#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_

#include <vector>
#include "game/scans/scan_object.h"
#include "sector_object.h"
#include "data/grid.h"
#include "data/coords.h"

class Sector {
 public:
  Sector(const ScanObject& scanData, size_t row, size_t col);

  void GenerateObjects();

  const Sector* kUp = nullptr;
  const Sector* kDown = nullptr;
  const Sector* kLeft = nullptr;
  const Sector* kRight = nullptr;
  Grid<SectorObjectType> GetSectorObjects() const;
  Coords GetRandomFreeCoords() const;
  bool IsPositionAvailable(Coords coords);
 private:
  ScanObject scan_data_;
  static const int kGridSize = 10;
  Grid<SectorObjectType> objects_;
  int row_;
  int col_;

  void PlaceObjectsOfType(SectorObjectType type, int amount);
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
