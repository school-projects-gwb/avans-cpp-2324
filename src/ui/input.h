#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_

#include "game.h"
#include "ui/user_actions/action_registry.h"

class Input {
 private:
  ActionRegistry action_registry_;
  void ShowAllowedCommands(Game& game) const;
 public:
  Input();
  void ProcessInput(Game& game) const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_
