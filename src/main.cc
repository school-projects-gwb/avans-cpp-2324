#include <iostream>
#include "ui/ui.h"
#include "game_manager.h"
#include "ui/input.h"
#include "database_connection.h"
#include "data_handler.h"

int main() {
  try {
    persistence::DatabaseConnection::GetInstance().ConnectToSqlite("planetexpress.db");
  } catch (std::runtime_error &ex) {
    std::cerr << ex.what();
    return 0;
  }

  persistence::DataHandler data_handler;
  auto packages = data_handler.GetPackages();
  auto encounters = data_handler.GetEncounters();
  bool should_quit = false;

  while (!should_quit) {
    auto game = game::GameManager(packages, encounters);
    auto ui = interface::Ui(game);
    auto input = interface::Input();
    ui.UpdateUi(game.GetMainGameState(), game.GetSubGameState());

    while (game.GetMainGameState() != game::enums::MainGameState::ShouldReset) {
      input.ProcessInput(game);
      ui.UpdateUi(game.GetMainGameState(), game.GetSubGameState());
      game.ResetSubGameState();
      should_quit = game.ShouldQuit();
    }
  }
}