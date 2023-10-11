#include "spaceship.h"
#include "data/movement_direction.h"

namespace Game {
  void SpaceShip::SetPosition(Coords new_position) {
    position_ = new_position;
  }

  Coords SpaceShip::GetNextMovementPosition(MovementDirection direction) const {
    auto next_position = position_;

    if (direction == Up || direction == Down)
      next_position.pos_y_ += direction == Up ? -1 : 1;

    if (direction == Left || direction == Right)
      next_position.pos_x_ += direction == Left ? -1 : 1;

    return next_position;
  }

  const Coords &SpaceShip::GetPosition() const {
    return position_;
  }
}
