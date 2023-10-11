#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_COMMAND_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_COMMAND_H_

#include "command_center.h"

namespace Game {
  class Command {
   public:
    virtual void HandleCommand(CommandCenter &game, int key) const = 0;
    virtual bool IsAllowed(CommandCenter &game) const = 0;
    virtual ~Command() = default;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_COMMAND_H_
