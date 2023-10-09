#include "view_package_command.h"
void ViewPackageCommand::HandleCommand(Game &game, int key) const {

}

bool ViewPackageCommand::IsAllowed(Game &game) const {
  return game.GetState() == Movement;
}
