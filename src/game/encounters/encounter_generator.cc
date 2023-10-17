#include "encounter_generator.h"
#include "helpers/random_helper.h"

namespace game {

EncounterGenerator::EncounterGenerator(std::vector<EncounterModel>& encounters) : encounters_(encounters) {

}

void EncounterGenerator::GenerateResult(SpaceshipStats& spaceship_stats, enums::EncounterCharacter encounter_character) {
  AddEncounterLogRecord("Je koos: " + enums::GetEncounterCharacterFromEnum(encounter_character));
  auto source = encounter_character == enums::Bender ? GetRandomCharacter(enums::BenderSuccess, enums::BenderFailure) : encounter_character;

  std::vector<Consequence> possible_consequences;

  for (const Consequence& consequence : current_encounter_.consequences)
    if (consequence.consequence_source == source) possible_consequences.push_back(consequence);

  if (possible_consequences.empty()) return;

  int randomIndex = random_helper_.GenerateRandomInt(0, possible_consequences.size() - 1);

  Consequence random_consequence = possible_consequences[randomIndex];
  AddEncounterLogRecord(random_consequence.description);
  ProcessConsequenceResult(random_consequence, spaceship_stats);
}

void EncounterGenerator::ProcessConsequenceResult(const Consequence& consequence, SpaceshipStats& spaceship_stats) {
  switch (consequence.consequence_type) {
    case enums::Geen:
      AddEncounterLogRecord("Er is niks gebeurd en je bent veilig weggekomen");
      break;
    case enums::Overwinningspunt:
      AddEncounterLogRecord("Je krijgt (" + std::to_string(consequence.amount) + ") overwinningspunten");
      spaceship_stats.AppendWinningPoints(consequence.amount);
      break;
    case enums::Reparatie:
      AddEncounterLogRecord("Je hebt geluk; al je schadepunten worden gerepareerd!");
      spaceship_stats.ResetDamagePoints();
      break;
    case enums::Schade:
      AddEncounterLogRecord("Je raakt in gevecht met " + current_encounter_.description + "!");
      ProcessFight(consequence, spaceship_stats);
      break;
    default:
      break;
  }
}

void EncounterGenerator::ProcessFight(const Consequence& consequence, SpaceshipStats& spaceship_stats) {
  const int hit_count_before_fight_over = 3;
  int enemy_hit_count = 0;
  int min_dice_amount = 1, max_dice_amount = 6;

  while (enemy_hit_count < hit_count_before_fight_over && !spaceship_stats.IsDestroyed()) {
    // Deal damage to spaceship
    int dice_thrown = 0, damage_to_deal = 0;
    while (dice_thrown < consequence.amount) {
      damage_to_deal += random_helper_.GenerateRandomInt(min_dice_amount, max_dice_amount);
      dice_thrown++;
    }

    spaceship_stats.AppendDamagePoints(damage_to_deal);
    AddEncounterLogRecord(current_encounter_.description + " doet " + std::to_string(damage_to_deal)
    + " punten schade. Je hebt in totaal " + std::to_string(spaceship_stats.GetDamagePoints()) + " schadepunten.");
    if (spaceship_stats.IsDestroyed()) break;

    // Deal damage to consequence
    int can_attack = random_helper_.GenerateRandomInt(0, 1);
    if (can_attack == 0) {
      AddEncounterLogRecord("Je schiet en mist.");
      continue;
    }

    enemy_hit_count++;
    AddEncounterLogRecord("Je schiet en raakt. " + std::to_string(enemy_hit_count) + " raak geschoten!");
  }

  if (spaceship_stats.IsDestroyed()) {
    AddEncounterLogRecord(current_encounter_.description + " heeft je verslagen! Game-over.");
  } else {
    AddEncounterLogRecord(current_encounter_.description  + " is verslagen!");
  }
}

enums::EncounterCharacter EncounterGenerator::GetRandomCharacter(enums::EncounterCharacter character_one,
                                                                 enums::EncounterCharacter character_two) {
  return random_helper_.GenerateRandomInt(0, 1) == 0 ? character_one : character_two;
}

const std::vector<std::string>& EncounterGenerator::GetLatestEncounterLog() const {
  return current_encounter_log;
}

void EncounterGenerator::CreateRandomEncounter() {
  current_encounter_log.clear();
  current_encounter_ = encounters_.at(random_helper_.GenerateRandomInt(0, encounters_.size()-1));
  AddEncounterLogRecord("Het ruimteschip USS Planet Express Ship komt tegen: " + current_encounter_.description);
}

void EncounterGenerator::AddEncounterLogRecord(const std::string& content) {
  current_encounter_log.emplace_back(content);
}

}
