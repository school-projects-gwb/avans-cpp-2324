#include "cargo.h"
#include "data_models/package_model.h"

namespace game {

void Cargo::UpdateStatus(bool is_in_transit) {
  is_in_transit_ = is_in_transit;
}

void Cargo::AddCargo(const PackageModel& package, PackageDestinationResult destination_info) {
  current_shipment_.source_sector = destination_info.current_sector_coords;
  current_shipment_.destination_sector = destination_info.destination_sector_coords;
  current_shipment_.destination_planet = destination_info.destination_planet_coords;

  current_shipment_.destination_description = package.destination_description_;
  current_shipment_.content_description = package.content_description_;

  is_in_transit_ = true;
}

CargoInfo Cargo::GetCargoInfo() const {
  return {is_in_transit_, current_shipment_};
}

bool Cargo::GetIsInTransit() const {
  return is_in_transit_;
}

}