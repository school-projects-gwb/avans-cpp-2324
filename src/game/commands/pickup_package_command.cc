#include "pickup_package_command.h"

namespace Game {
  void PickupPackageCommand::HandleCommand(CommandCenter &game, int key) const {

  }

  bool PickupPackageCommand::IsAllowed(const CommandCenter &game) const {
    if (game.GetState() != Movement) return false;

    const auto& space_ship = game.GetSpaceship();
    return space_ship.HasNeighborOfType(SectorObjectType::Planet) && !space_ship.HasCargo();
  }
}
