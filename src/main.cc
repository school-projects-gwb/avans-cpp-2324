#include "ui/ui.h"
#include "game_manager.h"
#include "ui/input.h"

int main() {
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