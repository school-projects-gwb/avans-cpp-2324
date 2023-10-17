#include "move_command.h"
#include "game/enums/direction.h"

namespace game {
  void MoveCommand::HandleCommand(GameManager &game, int key) const {
    if (!IsAllowed(game)) return;

    enums::Direction movement_direction;

    switch (key) {
      case 1:movement_direction = enums::Up;
        break;
      case 2:movement_direction = enums::Down;
        break;
      case 3:movement_direction = enums::Left;
        break;
      case 4:movement_direction = enums::Right;
        break;
      default:movement_direction = enums::None;
    }

    game.ProcessPlayerMovement(movement_direction);
  }

  bool MoveCommand::IsAllowed(const GameManager &game) const {
    return game.GetMainGameState() == enums::Movement;
  }
}