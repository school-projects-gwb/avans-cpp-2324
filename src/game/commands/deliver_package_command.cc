#include "deliver_package_command.h"

namespace Game {
  void DeliverPackageCommand::HandleCommand(CommandCenter &game, int key) const {

  }

  bool DeliverPackageCommand::IsAllowed(CommandCenter &game) const {
    return game.GetState() == Movement;
  }
}