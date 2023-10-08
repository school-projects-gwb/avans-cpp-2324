#include <ctime>
#include <cstdlib>
#include "scanner.h"

void Scanner::Scan() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  for (int row = 0; row < kColRowCount; row++) {
    for (int col = 0; col < kColRowCount; col++) {
      scan_[row][col].asteroid_amount = std::rand() % 10;
      scan_[row][col].planet_amount = std::rand() % 3;
      scan_[row][col].encounter_amount = std::rand() % 4;
    }
  }
}
