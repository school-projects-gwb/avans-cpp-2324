#include "action_registry.h"
#include "commands/move_command.h"
#include "commands/pickup_package_command.h"
#include "commands/view_package_command.h"
#include "commands/deliver_package_command.h"
#include "commands/empty_command.h"

ActionRegistry::ActionRegistry() {
  hotkeys_.push_back({1, new MoveCommand(), "Naar boven bewegen"});
  hotkeys_.push_back({2, new MoveCommand(), "Naar beneden bewegen"});
  hotkeys_.push_back({3, new MoveCommand(), "Naar links bewegen"});
  hotkeys_.push_back({4, new MoveCommand(), "Naar rechts bewegen"});
  hotkeys_.push_back({5, new PickupPackageCommand(), "Pakketje oppikken"});
  hotkeys_.push_back({6, new ViewPackageCommand(), "Pakketje bekijken"});
  hotkeys_.push_back({7, new DeliverPackageCommand(), "Pakketje bezorgen"});
  hotkeys_.push_back({7, new EmptyCommand(), "Niets doen"});
}

ActionRegistry::~ActionRegistry() {
  for (UserAction& hotkey : hotkeys_)
    delete hotkey.command;
}

void ActionRegistry::HandleCommand(int input_value, Game& game) const {
  auto it = std::find_if(hotkeys_.begin(), hotkeys_.end(),
                         [input_value](const UserAction& hotkey) {
                           return hotkey.key == input_value;
                         });

  if (it != hotkeys_.end()) {
    it->command->HandleCommand(game, input_value);
  } else {
    game.ProcessPlayerInput(input_value);
  }
}
