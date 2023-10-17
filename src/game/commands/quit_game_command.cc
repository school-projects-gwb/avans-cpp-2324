#include "quit_game_command.h"

namespace game {

void game::QuitGameCommand::HandleCommand(game::GameManager &game, int key) const {
  game.QuitGame();
}

bool game::QuitGameCommand::IsAllowed(const game::GameManager &game) const {
  auto state = game.GetMainGameState();
  return state == enums::MainGameState::PendingReset || state == enums::MainGameState::HasWon || state == enums::MainGameState::HasLost;
}

}
