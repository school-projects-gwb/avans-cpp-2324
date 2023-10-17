#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_CONSEQUENCE_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_CONSEQUENCE_H_

#include <string>
#include "enums/encounter_character.h"
#include "enums/encounter_consequence_type.h"

namespace game {

struct Consequence {
  enums::EncounterConsequenceType consequence_type;
  enums::EncounterCharacter consequence_source;
  int amount;
  std::string description;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_CONSEQUENCE_H_
