#include "encounter_generator.h"

namespace game {

EncounterGenerator::EncounterGenerator(std::vector<EncounterModel>& encounters) : encounters_(encounters) {

}

void EncounterGenerator::Generate(SpaceshipStats spaceship_stats, enums::EncounterCharacter encounter_character) {

}

const std::vector<std::string>& EncounterGenerator::GetLatestEncounterLog() const {
  return latest_encounter_log_;
}

}
