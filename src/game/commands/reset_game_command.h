#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_RESET_GAME_COMMAND_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_RESET_GAME_COMMAND_H_

#include "game_manager.h"
#include "command.h"

namespace game {

class ResetGameCommand : public Command {
 public:
  void HandleCommand(GameManager &game, int key) const override;
  bool IsAllowed(const GameManager &game) const override;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_RESET_GAME_COMMAND_H_
