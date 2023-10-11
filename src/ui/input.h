#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_

#include "command_center.h"
#include "ui/user_actions/action_registry.h"

namespace Interface {
  class Input {
   private:
    ActionRegistry action_registry_;
    void ShowAllowedCommands(Game::CommandCenter &game) const;
   public:
    Input();
    void ProcessInput(Game::CommandCenter &game) const;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_
