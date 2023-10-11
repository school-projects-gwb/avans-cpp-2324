#include <iostream>
#include "ui/ui.h"
#include "command_center.h"
#include "ui/input.h"

int main() {
  Game::CommandCenter game = Game::CommandCenter();
  Interface::Ui ui = Interface::Ui(game);
  Interface::Input input = Interface::Input();
  ui.UpdateUi(game.GetState());

  while (true) {
    input.ProcessInput(game);
    ui.UpdateUi(game.GetState());
  }
}