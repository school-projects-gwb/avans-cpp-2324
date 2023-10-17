#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_MANAGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_MANAGER_H_

#include <vector>
#include "game/scans/scan_creator.h"
#include "game/enums/main_game_state.h"
#include "game/sectors/universe.h"
#include "game/spaceship/spaceship.h"
#include "game/enums/direction.h"
#include "game_state.h"
#include "data_models/encounter_model.h"

namespace game {
  class GameManager {
   private:
    ScanCreator scanner_;
    Universe universe_;
    SpaceShip space_ship_;
    GameState state_ = {};
    std::vector<PackageModel> package_data_;
    std::vector<EncounterModel> encounter_data_;
   public:
    explicit GameManager(std::vector<PackageModel>& package_data, std::vector<EncounterModel>& encounter_data);
    void MovePlayer(enums::Direction direction);
    void ProcessPlayerInput(int userInput);
    void ProcessPackagePickup();
    void ProcessPackageView();
    void ProcessPackageDeliver();
    void ResetGame();

    enums::MainGameState GetMainGameState() const;
    enums::SubGameState GetSubGameState() const;
    Grid<ScanObject> GetCurrentScan() const;
    Grid<enums::SectorObjectType> GetCurrentSector() const;
    const SpaceShip& GetSpaceship() const;
    void ResetSubGameState();
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_MANAGER_H_
