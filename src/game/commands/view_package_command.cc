#include "view_package_command.h"

namespace game {
  void ViewPackageCommand::HandleCommand(GameManager &game, int key) const {

  }

  bool ViewPackageCommand::IsAllowed(const GameManager &game) const {
    return game.GetState() == Movement && game.GetSpaceship().HasCargo();
  }
}