#include <string>
#include <iostream>
#include "scanner.h"
#include "helpers/random_helper.h"
#include "scan_pick_result.h"

void Scanner::Scan() {
  RandomHelper random_helper = RandomHelper::GetInstance();

  for (auto & row : scan_) {
    for (auto & col : row) {
      col.asteroid_amount = random_helper.GenerateRandomInt(0, 9);;
      col.planet_amount = random_helper.GenerateRandomInt(0, 3);
      col.encounter_amount = random_helper.GenerateRandomInt(0, 4);
    }
  }
}

const ScanPickResult Scanner::PickSectorByInput(int input) const {
  ScanPickResult result{};
  result.is_valid_ = false;
  result.row_number_ = -1;
  result.col_number_ = -1;

  std::string value_string = std::to_string(input);
  if (value_string.length() != 2) return result;

  int row_number = static_cast<int>(value_string[0] - '0');
  int col_number = static_cast<int>(value_string[1] - '0');
  if ((row_number < 0 || row_number > kColRowCount) || (col_number < 0 || col_number > kColRowCount)) return result;

  result.is_valid_ = true;
  result.row_number_ = row_number;
  result.col_number_ = col_number;

  return result;
}

std::vector<std::vector<ScanObject>> Scanner::GetCurrentScan() const {
  std::vector<std::vector<ScanObject>> scanVector(kColRowCount, std::vector<ScanObject>(kColRowCount));

  std::transform(scan_, scan_ + kColRowCount, scanVector.begin(),
                 [](const ScanObject(&row)[kColRowCount]) -> std::vector<ScanObject> {
                   return {row, row + kColRowCount};
                 });

  return scanVector;
}