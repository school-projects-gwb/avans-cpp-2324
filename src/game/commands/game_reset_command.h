#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_GAME_RESET_COMMAND_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_GAME_RESET_COMMAND_H_

#include "command_center.h"
#include "command.h"

namespace Game {
  class GameResetCommand : public Command {
   public:
    void HandleCommand(CommandCenter &game, int key) const override;
    bool IsAllowed(const CommandCenter &game) const override;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_GAME_RESET_COMMAND_H_
