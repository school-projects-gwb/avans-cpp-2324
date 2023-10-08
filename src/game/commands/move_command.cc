#include "move_command.h"

void MoveCommand::HandleCommand(Game &game, int key) const {
  game.HandlePlayerMovement(key);
}

bool MoveCommand::IsAllowed(Game &game) const {
  return game.GetState() == Main;
}
