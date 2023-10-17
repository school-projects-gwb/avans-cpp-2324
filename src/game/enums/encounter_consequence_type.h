#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENUMS_ENCOUNTER_CONSEQUENCE_TYPE_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENUMS_ENCOUNTER_CONSEQUENCE_TYPE_H_

#include <iostream>

namespace game::enums {

enum EncounterConsequenceType {
  Geen, Overwinningspunt, Reparatie, Schade, NoValidType
};

static EncounterConsequenceType GetEncounterConsequenceTypeFromString(std::string string_value) {
  EncounterConsequenceType character = NoValidType;

  if (string_value == "overwinningspunt") {
    character = Overwinningspunt;
  } else if(string_value == "geen") {
    character = Geen;
  } else if (string_value == "schade") {
    character = Schade;
  } else if (string_value == "reparatiepunt") {
    character = Reparatie;
  }

  return character;
}

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENUMS_ENCOUNTER_CONSEQUENCE_TYPE_H_
