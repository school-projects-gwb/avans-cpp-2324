#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENUMS_ENCOUNTER_CHARACTER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENUMS_ENCOUNTER_CHARACTER_H_

#include <iostream>

namespace game::enums {

enum EncounterCharacter {
  Fry, Leela, Bender, BenderSuccess, BenderFailure, NoValidCharacter
};

static EncounterCharacter GetEncounterCharacterFromString(const std::string& string_value) {
  EncounterCharacter character = NoValidCharacter;

  if (string_value == "BenderSuccess") {
    character = BenderSuccess;
  } else if(string_value == "BenderFailure") {
    character = BenderFailure;
  } else if (string_value == "Fry") {
    character = Fry;
  } else if (string_value == "Leela") {
    character = Leela;
  }

  return character;
}

static std::string GetEncounterCharacterFromEnum(EncounterCharacter encounter_character) {
  switch (encounter_character) {
    case Bender:
      return "Bender";
    case Fry:
      return "Fry";
    case Leela:
      return "Leela";
    default:
      return "";
  }
}

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENUMS_ENCOUNTER_CHARACTER_H_
