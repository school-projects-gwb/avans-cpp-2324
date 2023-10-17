#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_SECTOR_OBJECT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_SECTOR_OBJECT_H_

#include "game/enums/sector_object_type.h"

namespace game {
  struct SectorObject {
    int pos_x_;
    int pos_y_;
    enums::SectorObjectType sector_object_type_;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_SECTOR_OBJECT_H_
