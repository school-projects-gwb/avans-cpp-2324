#include "empty_command.h"

void EmptyCommand::HandleCommand(Game &game, int key) const {

}
bool EmptyCommand::IsAllowed(Game &game) const {
  return game.state == 1;
}
