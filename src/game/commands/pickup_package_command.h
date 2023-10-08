#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_PICKUP_PACKAGE_COMMAND_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_PICKUP_PACKAGE_COMMAND_H_

#include "command.h"
class PickupPackageCommand : public Command {
 public:
  void HandleCommand(Game& game, int key) const override;
  bool IsAllowed(Game& game) const override;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_COMMANDS_PICKUP_PACKAGE_COMMAND_H_
