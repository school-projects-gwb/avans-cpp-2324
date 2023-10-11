#include "empty_command.h"

namespace Game {
  void EmptyCommand::HandleCommand(CommandCenter &game, int key) const {

  }

  bool EmptyCommand::IsAllowed(CommandCenter &game) const {
    return game.GetState() == Movement;
  }
}