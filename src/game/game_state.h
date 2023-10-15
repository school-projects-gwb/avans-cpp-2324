#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_STATE_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_STATE_H_

namespace game {
  enum GameState {
    Scanning, Movement, ActiveEncounter, Combat, PendingReset, ShouldReset
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_STATE_H_
