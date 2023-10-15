#include "pickup_package_command.h"

namespace game {
  void PickupPackageCommand::HandleCommand(GameManager &game, int key) const {

  }

  bool PickupPackageCommand::IsAllowed(const GameManager &game) const {
    if (game.GetState() != Movement) return false;

    const auto& space_ship = game.GetSpaceship();
    return space_ship.HasNeighborOfType(SectorObjectType::Planet) && !space_ship.HasCargo();
  }
}
