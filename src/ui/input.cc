#include <string>
#include <iostream>
#include "input.h"

const void Input::HandleInput(Game& game) {
  std::string input;

  std::cout << "Enter your choice: ";
  std::getline(std::cin, input);

  hotkey_manager_.HandleCommand(input[0], game);
}

Input::Input() : hotkey_manager_() {}
