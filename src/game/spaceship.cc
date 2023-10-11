#include "spaceship.h"

void SpaceShip::SetPosition(Coords new_position) {
  position_ = new_position;
}

Coords SpaceShip::GetNextMovementPosition(int direction) const {
  auto next_position = position_;

  if (direction >= 1 && direction <= 2)
    next_position.pos_y_ += direction == 1 ? -1 : 1;

  if (direction >= 3 && direction <= 4)
    next_position.pos_x_ += direction == 3 ? -1 : 1;

  return next_position;
}