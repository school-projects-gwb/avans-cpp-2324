#include "game_reset_command.h"

void Game::GameResetCommand::HandleCommand(Game::CommandCenter &game, int key) const {
  if (IsAllowed(game)) game.ResetGame();
}

bool Game::GameResetCommand::IsAllowed(const Game::CommandCenter &game) const {
  return game.GetState() == GameState::PendingReset;
}
