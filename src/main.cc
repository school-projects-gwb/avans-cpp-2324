#include <iostream>
#include "ui/ui.h"
#include "game_manager.h"
#include "ui/input.h"
#include "database_connection.h"

int main() {
  try {
    persistence::DatabaseConnection::GetInstance().ConnectToSqlite("planetexpress.db");
  } catch (std::runtime_error &ex) {
    std::cerr << ex.what();
    return 0;
  }

  while (true) {
    game::GameManager game = game::GameManager();
    interface::Ui ui = interface::Ui(game);
    interface::Input input = interface::Input();
    ui.UpdateUi(game.GetState());

    while (game.GetState() != game::GameState::ShouldReset) {
      input.ProcessInput(game);
      ui.UpdateUi(game.GetState());
    }
  }
}