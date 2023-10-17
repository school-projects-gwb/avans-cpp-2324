#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_

#include "scan_object.h"
#include "scan_select_result.h"
#include "data_types/grid.h"

namespace game {

class ScanCreator {
 public:
  ScanCreator();
  void CreateScan();
  ScanSelectResult PickSectorByInput(int input) const;
  Grid<ScanObject> GetCurrentScan() const;
  bool IsOnEdge(int row_number, int col_number) const;
 private:
  static const int kColRowCount = 5;
  Grid<ScanObject> scan_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_
