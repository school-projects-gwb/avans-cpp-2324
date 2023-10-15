#include "move_command.h"
#include "data/direction.h"

namespace game {
  void MoveCommand::HandleCommand(GameManager &game, int key) const {
    if (!IsAllowed(game)) return;

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

  bool MoveCommand::IsAllowed(const GameManager &game) const {
    return game.GetMainGameState() == Movement;
  }
}