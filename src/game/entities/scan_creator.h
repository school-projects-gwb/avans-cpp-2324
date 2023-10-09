#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_

#include "scan_object.h"
#include "scan_select_result.h"

class ScanCreator {
 private:
  static const int kColRowCount = 5;
  ScanObject scan_[kColRowCount][kColRowCount];

 public:
  void CreateScan();
  const ScanSelectResult PickSectorByInput(int input) const;
  std::vector<std::vector<ScanObject>> GetCurrentScan() const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_
