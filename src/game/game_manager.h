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
#include "encounters/encounter_generator.h"

namespace game {
  class GameManager {
   public:
    explicit GameManager(std::vector<PackageModel>& package_data, std::vector<EncounterModel>& encounter_data);

    void ProcessPlayerMovement(enums::Direction direction);
    void ProcessPlayerInput(int userInput);
    void ProcessPackagePickup();
    void ProcessPackageView();
    void ProcessPackageDeliver();
    void ProcessEncounter(enums::EncounterCharacter encounter_character);
    void ProcessDoNothing();

    void ResetSubGameState();
    void ResetGame();
    void QuitGame();

    [[nodiscard]] enums::MainGameState GetMainGameState() const;
    [[nodiscard]] enums::SubGameState GetSubGameState() const;
    [[nodiscard]] Grid<ScanObject> GetCurrentScan() const;
    [[nodiscard]] Grid<enums::SectorObjectType> GetCurrentSector() const;
    [[nodiscard]] const SpaceShip& GetSpaceship() const;
    [[nodiscard]] const std::vector<std::string>& GetEncounterLog() const;
    bool GetShouldQuit() const;
   private:
    ScanCreator scanner_;
    Universe universe_;
    SpaceShip space_ship_;
    GameState state_ = {};
    std::vector<PackageModel>& package_data_;
    EncounterGenerator encounter_generator_;
    bool should_quit_game_ = false;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_GAME_MANAGER_H_
