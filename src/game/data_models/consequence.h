#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_CONSEQUENCE_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_CONSEQUENCE_H_

#include <string>
#include "consequence_type.h"
#include "consequence_source.h"

namespace game {

struct Consequence {
  ConsequenceType consequence_type_;
  ConsequenceSource consequence_source_;
  int amount_;
  std::string description_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_CONSEQUENCE_H_
