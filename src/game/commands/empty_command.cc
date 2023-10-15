#include "empty_command.h"

namespace game {
  void EmptyCommand::HandleCommand(GameManager &game, int key) const {

  }

  bool EmptyCommand::IsAllowed(const GameManager &game) const {
    return game.GetMainGameState() == Movement || game.GetMainGameState() == PendingReset;
  }
}