#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENCOUNTERS_ENCOUNTER_GENERATOR_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENCOUNTERS_ENCOUNTER_GENERATOR_H_

#include <vector>
#include "data_models/encounter_model.h"
#include "spaceship/spaceship_stats.h"

namespace game {

class EncounterGenerator {
 public:
  static std::vector<std::string> Generate(std::vector<EncounterModel> encounters, SpaceshipStats spaceship_stats);
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENCOUNTERS_ENCOUNTER_GENERATOR_H_
