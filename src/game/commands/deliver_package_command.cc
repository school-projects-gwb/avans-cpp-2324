#include "deliver_package_command.h"

namespace game {
  void DeliverPackageCommand::HandleCommand(GameManager &game, int key) const {

  }

  bool DeliverPackageCommand::IsAllowed(const GameManager &game) const {
    return game.GetState() == Movement && game.GetSpaceship().CanDeliverCargo();
  }
}