#include "spaceship.h"

#include <utility>
#include "data/direction.h"

namespace game {
  void SpaceShip::SetPosition(Coords new_position, std::vector<SectorObjectType> neighbor_objects) {
    position_ = new_position;
    neighbor_objects_ = std::move(neighbor_objects);
  }

  Coords SpaceShip::GetNextMovementPosition(Direction direction) const {
    auto next_position = position_;

    if (direction == Up || direction == Down)
      next_position.pos_y_ += direction == Up ? -1 : 1;

    if (direction == Left || direction == Right)
      next_position.pos_x_ += direction == Left ? -1 : 1;

    return next_position;
  }

  bool SpaceShip::HasNeighborOfType(SectorObjectType object_type) const {
    return std::any_of(neighbor_objects_.begin(), neighbor_objects_.end(),
                       [object_type](SectorObjectType neighborObject) {
                         return neighborObject == object_type;
                       });
  }

  const Coords &SpaceShip::GetPosition() const {
    return position_;
  }

  bool SpaceShip::HasCargo() const {
    return cargo_.HasCargo();
  }

  bool SpaceShip::CanDeliverCargo() const {
    return false;
  }

  bool SpaceShip::IsAtUniverseEdge() const {
    return at_universe_edge;
  }

  void SpaceShip::SetIsAtUniverseEdge(bool is_at_edge) {
    at_universe_edge = is_at_edge;
  }
}
