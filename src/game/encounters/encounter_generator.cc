#include "encounter_generator.h"
#include "helpers/random_helper.h"
#include <iostream>

namespace game {

EncounterGenerator::EncounterGenerator(std::vector<EncounterModel>& encounters) : encounters_(encounters) {

}

void EncounterGenerator::Generate(SpaceshipStats spaceship_stats, enums::EncounterCharacter encounter_character) {
  latest_encounter_log_.clear();
  auto source = encounter_character == enums::Bender ? GetRandomCharacter(enums::BenderSuccess, enums::BenderFailure) : encounter_character;
  auto random_encounter = encounters_.at(random_helper_.GenerateRandomInt(0, encounters_.size()-1));

  std::cout << random_encounter.description_;
  latest_encounter_log_.emplace_back(random_encounter.description_);
}

enums::EncounterCharacter EncounterGenerator::GetRandomCharacter(enums::EncounterCharacter character_one,
                                                                 enums::EncounterCharacter character_two) {

  return random_helper_.GenerateRandomInt(0, 1) == 0 ? character_one : character_two;
}

const std::vector<std::string>& EncounterGenerator::GetLatestEncounterLog() const {
  return latest_encounter_log_;
}

}
