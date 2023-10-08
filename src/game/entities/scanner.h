#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_

#include "scan_object.h"
#include "scan_pick_result.h"

class Scanner {
 private:
  static const int kColRowCount = 5;
  ScanObject scan_[kColRowCount][kColRowCount];

 public:
  void Scan();
  const ScanPickResult PickSectorByInput(int input) const;
  std::vector<std::vector<ScanObject>> GetCurrentScan() const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_
