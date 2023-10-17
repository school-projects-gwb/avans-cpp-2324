#include "pickup_package_command.h"

namespace game {
  void PickupPackageCommand::HandleCommand(GameManager &game, int key) const {
    game.ProcessPackagePickup();
  }

  bool PickupPackageCommand::IsAllowed(const GameManager &game) const {
    if (game.GetMainGameState() != enums::Movement) return false;
    return game.GetSpaceship().CanPickupCargo();
  }
}
