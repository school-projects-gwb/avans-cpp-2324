#include <iostream>
#include "ui/ui.h"
#include "game_manager.h"
#include "ui/input.h"
#include "database_connection.h"
#include "data_handler.h"
#include "logger.h"

int main() {
  try {
    persistence::DatabaseConnection::GetInstance().ConnectToSqlite("planetexpress.db");
  } catch (const std::runtime_error &ex) {
    std::cerr << ex.what();
    return 0;
  }

  persistence::DataHandler data_handler;
  std::vector<game::PackageModel> packages;
  std::vector<game::EncounterModel> encounters;

  try {
    packages = data_handler.GetPackages();
    encounters = data_handler.GetEncounters();
  } catch(const std::runtime_error &ex) {
    std::cerr << ex.what();
    return 0;
  }

  bool should_quit = false;

  while (!should_quit) {
    auto game = game::GameManager(packages, encounters);
    auto ui = interface::Ui(game);
    auto input = interface::Input();
    ui.UpdateUi(game.GetMainGameState(), game.GetSubGameState());

    while (game.GetMainGameState() != game::enums::MainGameState::ShouldReset) {
      input.ProcessInput(game);
      game.MoveSectorObjects();
      ui.UpdateUi(game.GetMainGameState(), game.GetSubGameState());
      game.ResetSubGameState();
      should_quit = game.GetShouldQuit();
    }

    persistence::Logger::GetInstance().SaveLogToFile();
  }
}