#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_STATES_GAME_STATE_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_STATES_GAME_STATE_H_

#include "main_game_state.h"
#include "sub_game_state.h"
namespace game {

struct GameState {
  MainGameState main_game_state_;
  SubGameState sub_game_state_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_STATES_GAME_STATE_H_
