#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_

#include <vector>
#include "game/scans/scan_object.h"
#include "sector_object.h"

class Sector {
 public:
  Sector(const ScanObject& scanData, size_t row, size_t col);

  int GetRow() const;
  int GetCol() const;
  void GenerateObjects();

  const Sector* kUp = nullptr;
  const Sector* kDown = nullptr;
  const Sector* kLeft = nullptr;
  const Sector* kRight = nullptr;

 private:
  ScanObject scan_data_;
  std::vector<SectorObject> objects_;
  int row_;
  int col_;
  bool ObjectExistsAtPosition(int x, int y) const;
  SectorObject CreateObject(SectorObjectType object_type);
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTOR_H_
