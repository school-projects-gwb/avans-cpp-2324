#include <iostream>
#include "universe.h"
#include "scans/scan_creator.h"

namespace Game {
  void Universe::SetSectors(const Grid<ScanObject> &scanData, const ScanSelectResult &pickResult) {
    size_t numRows = scanData.GetRowCount();
    size_t numCols = scanData.ColColCount();

    sectors_.Resize(numRows, numCols, Sector(ScanObject{}, 0, 0));

    for (size_t row = 0; row < numRows; row++)
      for (size_t col = 0; col < numCols; col++)
        sectors_(row, col) = Sector(scanData(row, col), row, col);

    for (size_t row = 0; row < numRows; row++) {
      for (size_t col = 0; col < numCols; col++) {
        Sector &current_sector = sectors_(row, col);

        current_sector.kUp = (row > 0) ? &sectors_(row - 1, col) : nullptr;
        current_sector.kDown = (row < numRows - 1) ? &sectors_(row + 1, col) : nullptr;
        current_sector.kLeft = (col > 0) ? &sectors_(row, col - 1) : nullptr;
        current_sector.kRight = (col < numCols - 1) ? &sectors_(row, col + 1) : nullptr;
      }
    }

    active_sector_ = &sectors_(pickResult.row_number_, pickResult.col_number_);
    active_sector_->GenerateObjects();
  }

  Sector &Universe::GetActiveSector() const {
    return *active_sector_;
  }
}
