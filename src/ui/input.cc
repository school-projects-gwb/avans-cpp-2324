#include <string>
#include <iostream>
#include <sstream>
#include "input.h"

using namespace game;

namespace interface {
  Input::Input() : action_registry_() {}

  void Input::ProcessInput(GameManager &game) const {
    std::string input;
    int user_input;

    while (true) {
      ShowAllowedCommands(game);
      std::getline(std::cin, input);

      std::istringstream iss(input);

      if (iss >> user_input) {
        action_registry_.HandleCommand(user_input, game);
        break;
      }

      std::cout << "Deze input is niet toegestaan!\n";
    }
  }

  void Input::ShowAllowedCommands(GameManager &game) const {
    for (const UserAction &hotkey : action_registry_.hotkeys_)
      if (hotkey.command->IsAllowed(game)) std::cout << hotkey.key << " : " << hotkey.description << "\n";

    std::cout << "\n> ";
  }
}
