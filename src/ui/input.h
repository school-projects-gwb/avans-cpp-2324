#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_

#include "game_manager.h"
#include "ui/user_actions/action_registry.h"

namespace interface {
  class Input {
   public:
    Input();
    void ProcessInput(game::GameManager& game) const;
   private:
    ActionRegistry action_registry_;
    void ShowAllowedCommands(const game::GameManager& game) const;
    void PrintToOutput(const std::string &content) const;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_
