#include "ui/ui.h"
#include "command_center.h"
#include "ui/input.h"

int main() {
  while (true) {
    Game::CommandCenter game = Game::CommandCenter();
    Interface::Ui ui = Interface::Ui(game);
    Interface::Input input = Interface::Input();
    ui.UpdateUi(game.GetState());

    while (game.GetState() != Game::GameState::ShouldReset) {
      input.ProcessInput(game);
      ui.UpdateUi(game.GetState());
    }
  }
}