#include <iostream>
#include "game_manager.h"
#include "game/enums/direction.h"
#include "encounters/encounter_generator.h"

namespace game {
  GameManager::GameManager(std::vector<PackageModel>& package_data, std::vector<EncounterModel>& encounter_data) :
  scanner_(), universe_(), space_ship_(), encounter_generator_(encounter_data) {
    package_data_ = package_data;
    scanner_.CreateScan();
  }

  void GameManager::ResetGame() {
    state_.main_game_state_ = enums::MainGameState::ShouldReset;
  }

  void GameManager::MovePlayer(enums::Direction direction) {
    universe_.MoveSpaceship(direction);

    // We can return immediately without moving other objects when this happens
    if (space_ship_.IsAtUniverseEdge()) {
      state_.main_game_state_ = enums::MainGameState::PendingReset;
      return;
    }

    universe_.MoveObjects(space_ship_.GetPosition());
    auto collision_found =  universe_.TryRemoveCollidingObjects(space_ship_.GetPosition(), enums::SectorObjectType::Encounter);
    if (collision_found) state_.main_game_state_ = enums::MainGameState::ActiveEncounter;
  }

  void GameManager::ProcessEncounter(enums::EncounterCharacter encounter_character) {

  }

  void GameManager::ProcessPackagePickup() {
    auto package_destination_result = universe_.GetPackageDestinationInfo();
    if (!package_destination_result.has_valid_destination) {
      state_.main_game_state_ = enums::MainGameState::PackagePickupBlocked;
      return;
    }

    PackageModel package = PackageModel::GetRandomPackage(package_data_);
    space_ship_.AddCargo(package, package_destination_result);
    ProcessPackageView();
  }

  void GameManager::ProcessPackageView() {
    state_.sub_game_state_ = enums::SubGameState::ShowPackage;
  }

  enums::MainGameState GameManager::GetMainGameState() const {
    return state_.main_game_state_;
  }

  void GameManager::ProcessPlayerInput(int userInput) {
    std::cout << "HI";
    if (state_.main_game_state_ != enums::MainGameState::Scanning) return;

    auto sector_input_result = scanner_.PickSectorByInput(userInput);
    if (!sector_input_result.is_valid_) return;

    universe_.SetSectors(scanner_.GetCurrentScan(), sector_input_result);
    universe_.SetSpaceship(space_ship_);

    state_.main_game_state_ = enums::MainGameState::Movement;
  }

  Grid<ScanObject> GameManager::GetCurrentScan() const {
    return scanner_.GetCurrentScan();
  }

  const SpaceShip& GameManager::GetSpaceship() const {
    return space_ship_;
  }

  Grid<enums::SectorObjectType> GameManager::GetCurrentSector() const {
    return universe_.GetActiveSector().GetSectorObjects();
  }

  void GameManager::ProcessPackageDeliver() {
    space_ship_.DeliverCargo();
    state_.sub_game_state_ = enums::SubGameState::PackageDeliverySuccess;
  }

  enums::SubGameState GameManager::GetSubGameState() const {
    return state_.sub_game_state_;
  }

  void GameManager::ResetSubGameState() {
    state_.sub_game_state_ = enums::SubGameState::DoNothing;
  }
}
