#include "reset_game_command.h"

void game::ResetGameCommand::HandleCommand(game::GameManager &game, int key) const {
  if (IsAllowed(game)) game.ResetGame();
}

bool game::ResetGameCommand::IsAllowed(const game::GameManager &game) const {
  auto state = game.GetMainGameState();
  return state == enums::MainGameState::PendingReset || state == enums::MainGameState::HasWon || state == enums::MainGameState::HasLost;
}
