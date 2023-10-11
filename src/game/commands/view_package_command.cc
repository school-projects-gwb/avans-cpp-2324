#include "view_package_command.h"

namespace Game {
  void ViewPackageCommand::HandleCommand(CommandCenter &game, int key) const {

  }

  bool ViewPackageCommand::IsAllowed(const CommandCenter &game) const {
    return game.GetState() == Movement && game.GetSpaceship().HasCargo();
  }
}