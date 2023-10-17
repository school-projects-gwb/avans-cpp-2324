#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_ENCOUNTER_MODEL_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_ENCOUNTER_MODEL_H_

#include <string>
#include "consequence_type.h"
#include "consequence.h"

namespace game {

struct EncounterModel {
  std::vector<Consequence> consequences_;
  int id_;
  std::string description_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_ENCOUNTER_MODEL_H_
