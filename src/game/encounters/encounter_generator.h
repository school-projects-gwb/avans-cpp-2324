#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENCOUNTERS_ENCOUNTER_GENERATOR_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENCOUNTERS_ENCOUNTER_GENERATOR_H_

#include <vector>
#include "data_models/encounter_model.h"
#include "spaceship/spaceship_stats.h"
#include "enums/encounter_character.h"

namespace game {

class EncounterGenerator {
 public:
  explicit EncounterGenerator(std::vector<EncounterModel>& encounters);
  [[nodiscard]] const std::vector<std::string>& GetLatestEncounterLog() const;
  void Generate(SpaceshipStats spaceship_stats, enums::EncounterCharacter encounter_character);
 private:
  std::vector<EncounterModel> encounters_;
  std::vector<std::string> latest_encounter_log_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENCOUNTERS_ENCOUNTER_GENERATOR_H_
