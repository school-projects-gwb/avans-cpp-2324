#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_SHIPMENT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_SHIPMENT_H_

#include <string>
#include "data_types/coords.h"

namespace game {

struct Shipment {
  Coords destination_sector_;
  Coords destination_planet_;
  Coords source_sector_;
  std::string content_description_;
  std::string destination_description_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_SHIPMENT_H_
