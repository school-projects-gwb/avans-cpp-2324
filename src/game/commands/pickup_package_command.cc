#include "pickup_package_command.h"

namespace Game {
  void PickupPackageCommand::HandleCommand(CommandCenter &game, int key) const {

  }

  bool PickupPackageCommand::IsAllowed(CommandCenter &game) const {
    return game.GetState() == Movement;
  }
}
