#include "sector.h"
#include "helpers/random_helper.h"

Sector::Sector(const ScanObject& scanData, size_t row, size_t col)
    : scan_data_(scanData), row_(row), col_(col) {}

int Sector::GetRow() const {
  return row_;
}

int Sector::GetCol() const {
  return col_;
}

void Sector::GenerateObjects() {
  for (int i = 0; i < scan_data_.asteroid_amount; i++)
    objects_.push_back(CreateObject(SectorObjectType::Asteroid));

  for (int i = 0; i < scan_data_.planet_amount; i++)
    objects_.push_back(CreateObject(SectorObjectType::Planet));

  for (int i = 0; i < scan_data_.encounter_amount; i++)
    objects_.push_back(CreateObject(SectorObjectType::Encounter));
}

SectorObject Sector::CreateObject(SectorObjectType object_type) {
  RandomHelper random_helper = RandomHelper::GetInstance();

  SectorObject obj{};
  int pos_x, pos_y;
  do {
    pos_x = random_helper.GenerateRandomInt(0, col_ - 1);
    pos_y = random_helper.GenerateRandomInt(0, row_ - 1);
  } while (ObjectExistsAtPosition(pos_x, pos_y));

  obj.pos_x_ = pos_x;
  obj.pos_y_ = pos_y;
  obj.sector_object_type_ = object_type;

  return obj;
}

bool Sector::ObjectExistsAtPosition(int x, int y) const {
  for (const SectorObject& obj : objects_) {
    if (obj.pos_x_ == x && obj.pos_y_ == y) {
      return true; // Object exists at the specified position
    }
  }
  return false; // Object does not exist at the specified position
}
