#include "move_command.h"

void MoveCommand::HandleCommand(Game &game, int key) const {

}

bool MoveCommand::IsAllowed(Game &game) const {
  return game.state == 1;
}
