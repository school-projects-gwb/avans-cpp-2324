#include <string>
#include <iostream>
#include "scan_creator.h"
#include "helpers/random_helper.h"
#include "scan_select_result.h"

void ScanCreator::CreateScan() {
  RandomHelper random_helper = RandomHelper::GetInstance();

  for (auto & row : scan_) {
    for (auto & col : row) {
      col.asteroid_amount = random_helper.GenerateRandomInt(0, 9);;
      col.planet_amount = random_helper.GenerateRandomInt(0, 3);
      col.encounter_amount = random_helper.GenerateRandomInt(0, 4);
    }
  }
}

const ScanSelectResult ScanCreator::PickSectorByInput(int input) const {
  ScanSelectResult result{};
  result.is_valid_ = false;
  result.row_number_ = -1;
  result.col_number_ = -1;

  std::string value_string = std::to_string(input);
  if (value_string.length() != 2) return result;

  int row_number = static_cast<int>(value_string[0] - '0') - 1;
  int col_number = static_cast<int>(value_string[1] - '0') -1;

  std::cout << row_number << " " << col_number;

  if ((row_number == 0 || row_number == kColRowCount-1) && (col_number == 0 || col_number == kColRowCount-1)) {
    std::cout << "valid";
    result.is_valid_ = true;
    result.row_number_ = row_number;
    result.col_number_ = col_number;
    return result;
  }

  return result;
}

Grid ScanCreator::GetCurrentScan() const {
  std::vector<std::vector<ScanObject>> scanVector(kColRowCount, std::vector<ScanObject>(kColRowCount));

  std::transform(scan_, scan_ + kColRowCount, scanVector.begin(),
                 [](const ScanObject(&row)[kColRowCount]) -> std::vector<ScanObject> {
                   return {row, row + kColRowCount};
                 });

  return scanVector;
}