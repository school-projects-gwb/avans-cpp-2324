#include <string>
#include <iostream>
#include "scan_creator.h"
#include "helpers/random_helper.h"
#include "scan_select_result.h"

namespace game {
  ScanCreator::ScanCreator() : scan_(kColRowCount, kColRowCount) {
  }

  void ScanCreator::CreateScan() {
    RandomHelper random_helper = RandomHelper::GetInstance();

    for (auto &row : scan_) {
      for (auto &col : row) {
        col.asteroid_amount = random_helper.GenerateRandomInt(0, 9);;
        col.planet_amount = random_helper.GenerateRandomInt(0, 3);
        col.encounter_amount = random_helper.GenerateRandomInt(0, 4);
      }
    }
  }

  ScanSelectResult ScanCreator::PickSectorByInput(int input) {
    ScanSelectResult result{};
    result.is_valid = false;
    result.row_number = -1;
    result.col_number = -1;

    std::string value_string = std::to_string(input);
    if (value_string.length() != 2) return result;

    int row_number = static_cast<int>(value_string[0] - '0') - 1;
    int col_number = static_cast<int>(value_string[1] - '0') - 1;

    if (IsOnEdge(row_number, col_number)) {
      result.is_valid = true;
      result.row_number = row_number;
      result.col_number = col_number;
      return result;
    }

    return result;
  }

  bool ScanCreator::IsOnEdge(int row_number, int col_number) {
    if ((row_number == 0 || row_number == kColRowCount - 1) && (col_number >= 0 && col_number <= 5)) return true;
    if ((col_number == 0 || col_number == kColRowCount - 1) && (row_number >= 0 && row_number <= 5)) return true;

    return false;
  }

  const VectorGrid<ScanObject>& ScanCreator::GetCurrentScan() const {
    return scan_;
  }
}