#include "game_reset_command.h"

void game::GameResetCommand::HandleCommand(game::GameManager &game, int key) const {
  if (IsAllowed(game)) game.ResetGame();
}

bool game::GameResetCommand::IsAllowed(const game::GameManager &game) const {
  return game.GetMainGameState() == MainGameState::PendingReset;
}
