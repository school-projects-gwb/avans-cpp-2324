#include "spaceship.h"

#include <utility>
#include "game/enums/direction.h"

namespace game {

void SpaceShip::SetPosition(Coords sector_position, Coords universe_position, std::vector<SpaceshipNeighborObject> neighbor_objects) {
  sector_position_ = sector_position;
  universe_position_ = universe_position;
  neighbor_objects_ = std::move(neighbor_objects);
}

Coords SpaceShip::GetNextMovementPosition(enums::Direction direction) const {
  auto next_position = sector_position_;

  if (direction == enums::Up || direction == enums::Down)
    next_position.pos_y_ += direction == enums::Up ? -1 : 1;

  if (direction == enums::Left || direction == enums::Right)
    next_position.pos_x_ += direction == enums::Left ? -1 : 1;

  return next_position;
}

bool SpaceShip::HasNeighborOfType(enums::SectorObjectType object_type) const {
  return std::any_of(neighbor_objects_.begin(), neighbor_objects_.end(), [object_type](const SpaceshipNeighborObject& neighborObject) {
    return neighborObject.object_type_ == object_type;
  });
}

const Coords &SpaceShip::GetPosition() const {
  return sector_position_;
}

CargoInfo SpaceShip::GetCargoInfo() const {
  return cargo_.GetCargoInfo();
}

bool SpaceShip::IsAtUniverseEdge() const {
  return at_universe_edge;
}

void SpaceShip::SetIsAtUniverseEdge(bool is_at_edge) {
  at_universe_edge = is_at_edge;
}

void SpaceShip::AddCargo(const PackageModel& package, PackageDestinationResult destination_info) {
  cargo_.AddCargo(package, destination_info);
}

bool SpaceShip::CanDeliverCargo() const {
  auto cargo_info = GetCargoInfo();
  auto shipment = cargo_info.shipment_;

  if (!cargo_info.is_in_transit_ || !(shipment.destination_sector_ == universe_position_)) return false;

  Coords planet_destination = shipment.destination_planet_;

  return std::any_of(neighbor_objects_.begin(), neighbor_objects_.end(),
                     [planet_destination](const SpaceshipNeighborObject& neighbor) {
                       return neighbor.coords_ == planet_destination && neighbor.object_type_ == enums::SectorObjectType::Planet;
                     });
}

bool SpaceShip::CanPickupCargo() const {
  return HasNeighborOfType(enums::SectorObjectType::Planet) && !cargo_.GetIsInTransit();
}

bool SpaceShip::CanViewCargo() const {
  return cargo_.GetIsInTransit();
}

void SpaceShip::DeliverCargo() {
  cargo_.UpdateStatus(false);
}

SpaceshipStats& SpaceShip::GetStats() {
  return spaceship_stats_;
}

}
