#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_MAIN_GAME_STATE_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_MAIN_GAME_STATE_H_

namespace game::enums {
  enum MainGameState {
    Scanning, Movement, ActiveEncounter, Combat, PendingReset, ShouldReset,
    PackagePickupBlocked
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_MAIN_GAME_STATE_H_
