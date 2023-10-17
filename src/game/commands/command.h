#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_COMMAND_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_COMMAND_H_

#include "game_manager.h"

namespace game {
  class Command {
   public:
    virtual ~Command() = default;
    virtual void HandleCommand(GameManager &game, int key) const = 0;
    virtual bool IsAllowed(const GameManager &game) const = 0;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_COMMAND_H_
