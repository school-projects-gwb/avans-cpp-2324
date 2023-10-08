#include "ui/ui.h"
#include "game.h"
#include "ui/input.h"

int main() {
  Ui ui = Ui();
  Input input = Input();
  Game game = Game();

  while (true) input.HandleInput(game);
}