#include "deliver_package_command.h"

namespace game {
  void DeliverPackageCommand::HandleCommand(GameManager &game, int key) const {
    game.ProcessPackageDeliver();
  }

  bool DeliverPackageCommand::IsAllowed(const GameManager &game) const {
    return game.GetMainGameState() == Movement && game.GetSpaceship().CanDeliverCargo();
  }
}