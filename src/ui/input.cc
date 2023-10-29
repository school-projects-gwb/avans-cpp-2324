#include <string>
#include <iostream>
#include <sstream>
#include "input.h"
#include "logger.h"

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
    persistence::Logger::GetInstance().AppendLogRecord(" " + std::to_string(user_input) + " (User input)\n");

    if (iss >> user_input) {
      action_registry_.HandleCommand(user_input, game);
      break;
    }

    PrintToOutput("Deze input is niet toegestaan!\n");
  }
}

void Input::ShowAllowedCommands(const GameManager& game) const {
  PrintToOutput("Kies een actie:\n");
  for (const UserAction &hotkey : action_registry_.hotkeys_)
    if (hotkey.command->IsAllowed(game)) PrintToOutput(std::to_string(hotkey.key) + "  =  " + hotkey.description + "\n");

  PrintToOutput("\n> ");
}

void Input::PrintToOutput(const std::string& content) {
  std::cout << content;
  persistence::Logger::GetInstance().AppendLogRecord(content);
}

}
