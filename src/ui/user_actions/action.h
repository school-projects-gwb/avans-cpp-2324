#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_H_

#include <string>
#include <utility>
#include "commands/command.h"

namespace interface {

struct UserAction {
  int key;
  game::Command *command;
  std::string description;

  UserAction(int k, game::Command *cmd, std::string desc)
      : key(k), command(cmd), description(std::move(desc)) {}
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_H_
