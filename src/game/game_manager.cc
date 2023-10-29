#include <iostream>
#include "game_manager.h"
#include "game/enums/direction.h"
#include "encounters/encounter_generator.h"

namespace game {

GameManager::GameManager(const std::vector<PackageModel>& package_data, std::vector<EncounterModel>& encounter_data) :
scanner_(), universe_(), space_ship_(), encounter_generator_(encounter_data), package_data_(package_data) {
  scanner_.CreateScan();
}

void GameManager::ProcessPlayerMovement(const enums::Direction& direction) {
  universe_.MoveSpaceship(direction);
  if (space_ship_.IsAtUniverseEdge()) state_.main_game_state = enums::MainGameState::PendingReset;
}

void GameManager::ProcessObjectMovement() {
  if (state_.main_game_state != enums::Movement) return;

  universe_.MoveEncounters(space_ship_.GetPosition());
  auto collision_found = universe_.TryRemoveCollidingObjects(space_ship_.GetPosition(), enums::SectorObjectType::Encounter);
  if (collision_found) {
    state_.main_game_state = enums::MainGameState::ActiveEncounter;
    encounter_generator_.CreateRandomEncounter();
  }
}

void GameManager::ProcessPlayerInput(int userInput) {
  if (state_.main_game_state != enums::MainGameState::Scanning) return;

  auto sector_input_result = game::ScanCreator::PickSectorByInput(userInput);
  if (!sector_input_result.is_valid) return;

  universe_.SetSectors(scanner_.GetCurrentScan(), sector_input_result);
  universe_.SetSpaceship(space_ship_);

  state_.main_game_state = enums::MainGameState::Movement;
}

void GameManager::ProcessPackagePickup() {
  auto package_destination_result = universe_.GetPackageDestinationInfo();
  if (!package_destination_result.has_valid_destination) {
    state_.sub_game_state = enums::SubGameState::PackagePickupBlocked;
    return;
  }

  PackageModel package = PackageModel::GetRandomPackage(package_data_);
  space_ship_.AddCargo(package, package_destination_result);
  ProcessPackageView();
}

void GameManager::ProcessPackageView() {
  state_.sub_game_state = enums::SubGameState::ShowPackage;
}

void GameManager::ProcessPackageDeliver() {
  space_ship_.DeliverCargo();
  state_.sub_game_state = enums::SubGameState::PackageDeliverySuccess;
  if (!space_ship_.HasEnoughWinningPoints()) {
    state_.main_game_state = enums::Scanning;
    scanner_.CreateScan();
    return;
  }

  state_.main_game_state = enums::MainGameState::HasWon;
}

void GameManager::ProcessEncounter(const enums::EncounterCharacter& encounter_character) {
  encounter_generator_.GenerateResult(space_ship_.GetStats(), encounter_character);
  state_.sub_game_state = enums::SubGameState::ShowEncounter;
  state_.main_game_state = space_ship_.IsDestroyed() ? enums::MainGameState::HasLost : enums::MainGameState::Movement;
}

void GameManager::ProcessDoNothing() {
  state_.main_game_state = enums::MainGameState::Movement;
}

void GameManager::ResetGame() {
  state_.main_game_state = enums::MainGameState::ShouldReset;
}

void GameManager::ResetSubGameState() {
  state_.sub_game_state = enums::SubGameState::DoNothing;
}

void GameManager::QuitGame() {
  ResetGame();
  should_quit_game_ = true;
}

enums::MainGameState GameManager::GetMainGameState() const {
  return state_.main_game_state;
}

enums::SubGameState GameManager::GetSubGameState() const {
  return state_.sub_game_state;
}

const VectorGrid<ScanObject>& GameManager::GetCurrentScan() const {
  return scanner_.GetCurrentScan();
}

const VectorGrid<enums::SectorObjectType>& GameManager::GetCurrentSector() const {
  return universe_.GetActiveSector().GetSectorObjects();
}

const Coords GameManager::GetCurrentSectorCoords() const {
  return universe_.GetActiveSector().GetPositionInUniverse();
}

const SpaceShip& GameManager::GetSpaceship() const {
  return space_ship_;
}

const std::vector<std::string>& GameManager::GetEncounterLog() const {
  return encounter_generator_.GetLatestEncounterLog();
}

bool GameManager::GetShouldQuit() const {
  return should_quit_game_;
}

}
