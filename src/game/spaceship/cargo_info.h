#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_CARGO_INFO_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_CARGO_INFO_H_

#include "shipment.h"

namespace game {

struct CargoInfo {
  bool is_in_transit = false;
  const Shipment& shipment;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_CARGO_INFO_H_
