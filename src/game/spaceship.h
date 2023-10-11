#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_

#include "data/coords.h"
class SpaceShip {
 public:
  Coords GetNextMovementPosition(int direction) const;
  void SetPosition(Coords new_position);
 private:
  Coords position_;
  // package
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
