#include <iostream>
#include "game_manager.h"
#include "data/direction.h"

namespace game {
  GameManager::GameManager(std::vector<PackageModel>& package_data) : scanner_(), universe_(), space_ship_() {
    package_data_ = package_data;
    scanner_.CreateScan();
  }

  void GameManager::ResetGame() {
    state_.main_game_state_ = MainGameState::ShouldReset;
  }

  void GameManager::MovePlayer(Direction direction) {
    universe_.MoveSpaceship(direction);
    universe_.MoveObjects(space_ship_.GetPosition());
    if (space_ship_.IsAtUniverseEdge()) state_.main_game_state_ = MainGameState::PendingReset;
  }

  void GameManager::ProcessPackagePickup() {
    auto package_destination_result = universe_.GetPackageDestinationInfo();
    if (!package_destination_result.has_valid_destination) {
      state_.main_game_state_ = MainGameState::PackagePickupBlocked;
      return;
    }

    PackageModel package = PackageModel::GetRandomPackage(package_data_);
    space_ship_.AddCargo(package, package_destination_result);
    ProcessPackageView();
  }

  void GameManager::ProcessPackageView() {
    state_.sub_game_state_ = SubGameState::ShowPackage;
  }

  MainGameState GameManager::GetMainGameState() const {
    return state_.main_game_state_;
  }

  void GameManager::ProcessPlayerInput(int userInput) {
    if (state_.main_game_state_ != MainGameState::Scanning) return;

    auto sector_input_result = scanner_.PickSectorByInput(userInput);
    if (!sector_input_result.is_valid_) return;

    universe_.SetSectors(scanner_.GetCurrentScan(), sector_input_result);
    universe_.SetSpaceship(space_ship_);

    state_.main_game_state_ = MainGameState::Movement;
  }

  Grid<ScanObject> GameManager::GetCurrentScan() const {
    return scanner_.GetCurrentScan();
  }

  const SpaceShip& GameManager::GetSpaceship() const {
    return space_ship_;
  }

  Grid<SectorObjectType> GameManager::GetCurrentSector() const {
    return universe_.GetActiveSector().GetSectorObjects();
  }

  void GameManager::ProcessPackageDeliver() {
    space_ship_.DeliverCargo();
    state_.sub_game_state_ = SubGameState::PackageDeliverySuccess;
  }

  SubGameState GameManager::GetSubGameState() const {
    return state_.sub_game_state_;
  }

  void GameManager::ResetSubGameState() {
    state_.sub_game_state_ = SubGameState::DoNothing;
  }
}
