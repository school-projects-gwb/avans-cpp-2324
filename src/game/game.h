#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_

#include <vector>
#include "game/scans/scan_creator.h"
#include "game_state.h"
#include "game/sectors/universe.h"
#include "spaceship.h"
#include "data/movement_direction.h"

class Game {
 private:
  ScanCreator scanner_;
  Universe universe_;
  SpaceShip space_ship_;
  GameState state_ = Scanning;
 public:
  Game();
  void MovePlayer(MovementDirection direction);
  void ProcessPlayerInput(int userInput);
  GameState GetState() const;
  Grid<ScanObject> GetCurrentScan() const;
  Grid<SectorObjectType> GetCurrentSector() const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_H_
