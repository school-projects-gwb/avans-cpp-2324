#include <iostream>
#include "ui/ui.h"
#include "game_manager.h"
#include "ui/input.h"
#include "database_connection.h"
#include "data_handler.h"
#include "logger.h"

void HandleDatabaseConnection() {
  try {
    persistence::DatabaseConnection::GetInstance().ConnectToSqlite("planetexpress.db");
  } catch (const std::runtime_error &ex) {
    std::cerr << ex.what();
    exit(1);
  }
}

void HandleDataRetrieval(persistence::DataHandler& data_handler, std::vector<game::PackageModel>& packages, std::vector<game::EncounterModel>& encounters) {
  try {
    packages = data_handler.GetPackages();
    encounters = data_handler.GetEncounters();
  } catch (const std::runtime_error &ex) {
    std::cerr << ex.what();
    exit(1);
  }
}

int main() {
  HandleDatabaseConnection();

  persistence::DataHandler data_handler;
  std::vector<game::PackageModel> packages;
  std::vector<game::EncounterModel> encounters;

  HandleDataRetrieval(data_handler, packages, encounters);

  bool should_quit = false;
  while (!should_quit) {
    auto game = game::GameManager(packages, encounters);
    auto ui = interface::Ui(game);
    auto input = interface::Input();
    ui.UpdateUi(game.GetMainGameState(), game.GetSubGameState());

    while (game.GetMainGameState() != game::enums::MainGameState::ShouldReset) {
      input.ParseInput(game);
      game.ProcessObjectMovement();
      ui.UpdateUi(game.GetMainGameState(), game.GetSubGameState());
      game.ResetSubGameState();
      should_quit = game.GetShouldQuit();
    }

    persistence::Logger::GetInstance().SaveLogToFile();
  }
}