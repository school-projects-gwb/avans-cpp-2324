#include "deliver_package_command.h"

void DeliverPackageCommand::HandleCommand(Game &game, int key) const {

}

bool DeliverPackageCommand::IsAllowed(Game &game) const {
  return game.GetState() == Movement;
}
