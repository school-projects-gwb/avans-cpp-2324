#include "ui/ui.h"
#include "game.h"
#include "ui/input.h"

int main() {
  Game game = Game();
  Ui ui = Ui(game);
  Input input = Input();
  ui.UpdateUi(game.GetState());

  while (true) {
    input.ProcessInput(game);
    ui.UpdateUi(game.GetState());
  }
}