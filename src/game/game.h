#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_

#include <vector>
#include "game/entities/scanner.h"
#include "game_state.h"
#include "entities/sectors/sector_manager.h"
class Game {
 private:
  Scanner scanner_;
  SectorManager sector_manager_;
  GameState state_ = Scan;
 public:
  Game();
  void HandlePlayerMovement(int direction);
  void HandlePlayerInputValue(int userInput);
  GameState GetState() const;
  std::vector<std::vector<ScanObject>> GetCurrentScan() const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_
