#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_NEIGHBOR_OBJECT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_NEIGHBOR_OBJECT_H_

#include "data_types/coords.h"
#include "game/enums/sector_object_type.h"

namespace game {

struct SpaceshipNeighborObject {
  Coords coords;
  enums::SectorObjectType object_type;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_NEIGHBOR_OBJECT_H_
