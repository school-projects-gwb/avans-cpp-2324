#include <iostream>
#include "sector_manager.h"

void SectorManager::SetSectors(const std::vector<std::vector<ScanObject>> &scanData, const ScanPickResult &pickResult) {
  size_t numRows = scanData.size();
  size_t numCols = (numRows > 0) ? scanData[0].size() : 0;

  sectors_.resize(numRows, std::vector<Sector>(numCols, Sector(ScanObject{}, 0, 0)));

  for (size_t row = 0; row < numRows; row++) {
    for (size_t col = 0; col < numCols; col++) {
      sectors_[row][col] = Sector(scanData[row][col], row, col);
    }
  }

  active_sector_ = &sectors_[pickResult.row_number_][pickResult.col_number_];
}
