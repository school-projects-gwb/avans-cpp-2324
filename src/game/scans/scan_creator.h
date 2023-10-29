#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_

#include "scan_object.h"
#include "scan_select_result.h"
#include "data_types/vector_grid.h"

namespace game {

class ScanCreator {
 public:
  ScanCreator();
  void CreateScan();
  [[nodiscard]] static ScanSelectResult PickSectorByInput(int input);
  [[nodiscard]] const VectorGrid<ScanObject>& GetCurrentScan() const;
  [[nodiscard]] static bool IsOnEdge(int row_number, int col_number);
 private:
  static const int kColRowCount = 5;
  VectorGrid<ScanObject> scan_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SCANNER_H_
