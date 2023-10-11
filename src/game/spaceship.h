#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_

#include "data/coords.h"
#include "data/movement_direction.h"

namespace Game {
  class SpaceShip {
   public:
    Coords GetNextMovementPosition(MovementDirection direction) const;
    void SetPosition(Coords new_position);
    const Coords &GetPosition() const;
   private:
    Coords position_;
    // package
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
