#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_SHIPMENT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_SHIPMENT_H_

#include <string>
#include "data_types/coords.h"

namespace game {

struct Shipment {
  Coords destination_sector;
  Coords destination_planet;
  Coords source_sector;
  std::string content_description;
  std::string destination_description;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_SHIPMENT_H_
