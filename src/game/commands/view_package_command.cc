#include "view_package_command.h"

namespace game {
  void ViewPackageCommand::HandleCommand(GameManager &game, int key) const {
    game.ProcessPackageView();
  }

  bool ViewPackageCommand::IsAllowed(const GameManager &game) const {
    return game.GetMainGameState() == Movement && game.GetSpaceship().CanViewCargo();
  }
}