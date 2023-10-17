#include "action_registry.h"
#include "commands/move_command.h"
#include "commands/pickup_package_command.h"
#include "commands/view_package_command.h"
#include "commands/deliver_package_command.h"
#include "commands/empty_command.h"
#include "commands/reset_game_command.h"
#include "commands/encounter_character_command.h"
#include "commands/quit_game_command.h"

using namespace game;

namespace interface {
  ActionRegistry::ActionRegistry() {
    hotkeys_.push_back({1, new MoveCommand(), "Naar boven bewegen"});
    hotkeys_.push_back({2, new MoveCommand(), "Naar beneden bewegen"});
    hotkeys_.push_back({3, new MoveCommand(), "Naar links bewegen"});
    hotkeys_.push_back({4, new MoveCommand(), "Naar rechts bewegen"});
    hotkeys_.push_back({5, new PickupPackageCommand(), "Pakketje oppikken"});
    hotkeys_.push_back({6, new ViewPackageCommand(), "Pakketje bekijken"});
    hotkeys_.push_back({7, new DeliverPackageCommand(), "Pakketje bezorgen"});
    hotkeys_.push_back({8, new EmptyCommand(), "Niets doen"});
    hotkeys_.push_back({9, new ResetGameCommand(), "Reset spel"});
    hotkeys_.push_back({10, new QuitGameCommand(), "Stop met spelen"});
    hotkeys_.push_back({1, new EncounterCharacterCommand(), "Fry"});
    hotkeys_.push_back({2, new EncounterCharacterCommand(), "Leela"});
    hotkeys_.push_back({3, new EncounterCharacterCommand(), "Bender"});
  }

  ActionRegistry::~ActionRegistry() {
    for (UserAction &hotkey : hotkeys_)
      delete hotkey.command;
  }

  void ActionRegistry::HandleCommand(int input_value, GameManager &game) const {
    auto it = std::find_if(hotkeys_.begin(), hotkeys_.end(),
                           [input_value, &game](const UserAction &hotkey) {
                             return hotkey.key == input_value && hotkey.command->IsAllowed(game);
                           });

    if (it != hotkeys_.end()) {
      it->command->HandleCommand(game, input_value);
    } else {
      game.ProcessPlayerInput(input_value);
    }
  }
}
