#include "cargo.h"
#include "data_models/package.h"

namespace game {

void Cargo::UpdateStatus(bool is_in_transit) {
  is_in_transit_ = is_in_transit;
}

void Cargo::AddCargo(const Package& package, PackageDestinationResult destination_info) {
  current_shipment_.source_sector_ = destination_info.current_sector_coords;
  current_shipment_.destination_sector_ = destination_info.destination_sector_coords;
  current_shipment_.destination_planet_ = destination_info.destination_planet_coords;

  current_shipment_.destination_description_ = package.destination_description_;
  current_shipment_.content_description_ = package.content_description_;

  is_in_transit_ = true;
}

CargoInfo Cargo::GetCargoInfo() const {
  CargoInfo cargo_info{};
  cargo_info.is_in_transit_ = is_in_transit_;
  cargo_info.shipment_ = current_shipment_;

  return cargo_info;
}

bool Cargo::GetIsInTransit() const {
  return is_in_transit_;
}

}