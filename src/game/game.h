#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_

#include "scanner.h"
class Game {
 private:
  Scanner scanner_;
 public:
  Game();
  void HandleInput(char input);
  void Move(int direction);
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_
