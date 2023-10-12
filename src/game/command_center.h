#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMAND_CENTER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMAND_CENTER_H_

#include <vector>
#include "game/scans/scan_creator.h"
#include "game_state.h"
#include "game/sectors/universe.h"
#include "game/spaceship/spaceship.h"
#include "data/direction.h"

namespace Game {
  class CommandCenter {
   private:
    ScanCreator scanner_;
    Universe universe_;
    SpaceShip space_ship_;
    GameState state_ = Scanning;
   public:
    CommandCenter();
    void MovePlayer(Direction direction);
    void ProcessPlayerInput(int userInput);
    void ResetGame();
    GameState GetState() const;
    Grid<ScanObject> GetCurrentScan() const;
    Grid<SectorObjectType> GetCurrentSector() const;
    const SpaceShip& GetSpaceship() const;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMAND_CENTER_H_
