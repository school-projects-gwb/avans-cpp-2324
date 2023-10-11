#include "move_command.h"
#include "data/direction.h"

namespace Game {
  void MoveCommand::HandleCommand(CommandCenter &game, int key) const {
    Direction movement_direction;

    switch (key) {
      case 1:movement_direction = Up;
        break;
      case 2:movement_direction = Down;
        break;
      case 3:movement_direction = Left;
        break;
      case 4:movement_direction = Right;
        break;
      default:movement_direction = None;
    }

    game.MovePlayer(movement_direction);
  }

  bool MoveCommand::IsAllowed(const CommandCenter &game) const {
    return game.GetState() == Movement;
  }
}