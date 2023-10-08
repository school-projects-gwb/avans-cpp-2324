#include <string>
#include <iostream>
#include <sstream>
#include "input.h"

Input::Input() : hotkey_manager_() {}

void Input::HandleInput(Game& game) const {
  std::string input;
  int userInput;

  while (true) {
    ShowAllowedCommands(game);
    std::getline(std::cin, input);

    std::istringstream iss(input);

    if (iss >> userInput) {
      hotkey_manager_.HandleCommand(userInput, game);
      break;
    }

    std::cout << "Deze input is niet toegestaan!\n";
  }
}

void Input::ShowAllowedCommands(Game& game) const {
  for(const Hotkey& hotkey : hotkey_manager_.hotkeys_)
    if (hotkey.command->IsAllowed(game)) std::cout << hotkey.key << " : " << hotkey.description << "\n";

  std::cout << "\n> ";
}
