#include "encounter_character_command.h"

namespace game {

bool EncounterCharacterCommand::IsAllowed(const GameManager &game) const {
  return game.GetMainGameState() == enums::ActiveEncounter;
}

void EncounterCharacterCommand::HandleCommand(GameManager &game, int key) const {
  enums::EncounterCharacter character;

  switch (key) {
    case 1:
      character = enums::EncounterCharacter::Fry;
      break;
    case 2:
      character = enums::EncounterCharacter::Leela;
      break;
    case 3:
      character = enums::EncounterCharacter::Bender;
      break;
    default:
      character = enums::EncounterCharacter::Fry;
  }

  game.ProcessEncounter(character);
}

}