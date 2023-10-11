#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_EMPTY_COMMAND_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_EMPTY_COMMAND_H_

#include "command.h"

namespace Game {
  class EmptyCommand : public Command {
   public:
    void HandleCommand(CommandCenter &game, int key) const override;
    bool IsAllowed(CommandCenter &game) const override;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_EMPTY_COMMAND_H_
