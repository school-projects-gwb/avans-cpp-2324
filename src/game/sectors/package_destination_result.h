#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_PACKAGE_DESTINATION_RESULT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_PACKAGE_DESTINATION_RESULT_H_

#include "data_types/coords.h"
namespace game {

struct PackageDestinationResult {
  bool has_valid_destination = false;
  Coords destination_sector_coords{};
  Coords destination_planet_coords{};
  Coords current_sector_coords{};
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SECTORS_PACKAGE_DESTINATION_RESULT_H_
