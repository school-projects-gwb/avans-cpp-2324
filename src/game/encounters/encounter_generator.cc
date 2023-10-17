#include "encounter_generator.h"
#include "helpers/random_helper.h"
#include <iostream>

namespace game {

EncounterGenerator::EncounterGenerator(std::vector<EncounterModel>& encounters) : encounters_(encounters) {

}

void EncounterGenerator::GenerateResult(SpaceshipStats spaceship_stats, enums::EncounterCharacter encounter_character) {
  auto source = encounter_character == enums::Bender ? GetRandomCharacter(enums::BenderSuccess, enums::BenderFailure) : encounter_character;

  std::vector<Consequence> matchingConsequences;

  for (const Consequence& consequence : current_encounter_.consequences_)
    if (consequence.consequence_source_ == source) matchingConsequences.push_back(consequence);

  if (matchingConsequences.empty()) return;

  int randomIndex = random_helper_.GenerateRandomInt(0, matchingConsequences.size() - 1);

  Consequence randomConsequence = matchingConsequences[randomIndex];

  std::cout << "\n" << current_encounter_.description_ + "\n";
  std::cout << randomConsequence.description_ + "\n";
}

enums::EncounterCharacter EncounterGenerator::GetRandomCharacter(enums::EncounterCharacter character_one,
                                                                 enums::EncounterCharacter character_two) {

  return random_helper_.GenerateRandomInt(0, 1) == 0 ? character_one : character_two;
}

const std::vector<std::string>& EncounterGenerator::GetLatestEncounterLog() const {
  return latest_encounter_log_;
}

void EncounterGenerator::CreateRandomEncounter() {
  latest_encounter_log_.clear();
  current_encounter_ = encounters_.at(random_helper_.GenerateRandomInt(0, encounters_.size()-1));
  latest_encounter_log_.emplace_back(current_encounter_.description_);
}

const std::string& EncounterGenerator::GetCurrentEncounterDescription() {
  return current_encounter_.description_;
}

}
