#include <cstdio>
#include "sector.h"

Sector::Sector(const ScanObject& scanData, size_t row, size_t col)
    : scan_data_(scanData), row_(row), col_(col) {}

int Sector::GetAsteroidAmount() const {
  return scan_data_.asteroid_amount;
}

int Sector::GetPlanetAmount() const {
  return scan_data_.planet_amount;
}

int Sector::GetEncounterAmount() const {
  return scan_data_.encounter_amount;
}

int Sector::GetRow() const {
  return row_;
}

int Sector::GetCol() const {
  return col_;
}