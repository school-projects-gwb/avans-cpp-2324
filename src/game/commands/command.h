#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_COMMAND_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_COMMAND_H_

#include "game.h"

class Command {
 public:
  virtual void HandleCommand(Game& game, int key) const = 0;
  virtual ~Command() = default;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_COMMAND_H_
