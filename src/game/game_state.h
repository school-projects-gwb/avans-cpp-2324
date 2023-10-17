#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_STATES_GAME_STATE_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_STATES_GAME_STATE_H_

#include "game/enums/main_game_state.h"
#include "game/enums/sub_game_state.h"
namespace game {

struct GameState {
  enums::MainGameState main_game_state = enums::Scanning;
  enums::SubGameState sub_game_state = enums::DoNothing;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_STATES_GAME_STATE_H_
