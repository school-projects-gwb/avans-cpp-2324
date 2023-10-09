#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_

#include <vector>
#include "game/scans/scan_creator.h"
#include "game_state.h"
#include "game/sectors/universe.h"

class Game {
 private:
  ScanCreator scanner_;
  Universe universe_;
  GameState state_ = Scanning;
 public:
  Game();
  void MovePlayer(int direction);
  void ProcessPlayerInput(int userInput);
  GameState GetState() const;
  Grid<ScanObject> GetCurrentScan() const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_
