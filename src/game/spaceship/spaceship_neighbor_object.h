#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_NEIGHBOR_OBJECT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_NEIGHBOR_OBJECT_H_

#include "data/coords.h"
#include "sectors/sector_object_type.h"

namespace game {

struct SpaceshipNeighborObject {
  Coords coords_;
  SectorObjectType object_type_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_NEIGHBOR_OBJECT_H_
