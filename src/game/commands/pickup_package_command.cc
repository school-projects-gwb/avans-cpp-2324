#include "pickup_package_command.h"

void PickupPackageCommand::HandleCommand(Game &game, int key) const {

}

bool PickupPackageCommand::IsAllowed(Game &game) const {
  return game.GetState() == Movement;
}
