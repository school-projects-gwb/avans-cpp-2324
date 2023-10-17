#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENCOUNTERS_ENCOUNTER_GENERATOR_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENCOUNTERS_ENCOUNTER_GENERATOR_H_

#include <vector>
#include "data_models/encounter_model.h"
#include "spaceship/spaceship_stats.h"
#include "enums/encounter_character.h"
#include "helpers/random_helper.h"

namespace game {

class EncounterGenerator {
 public:
  explicit EncounterGenerator(std::vector<EncounterModel>& encounters);
  [[nodiscard]] const std::vector<std::string>& GetLatestEncounterLog() const;
  void GenerateResult(SpaceshipStats& spaceship_stats, enums::EncounterCharacter encounter_character);
  void CreateRandomEncounter();
 private:
  EncounterModel current_encounter_;
  RandomHelper random_helper_ = RandomHelper::GetInstance();
  std::vector<EncounterModel> encounters_;
  std::vector<std::string> current_encounter_log;
  enums::EncounterCharacter GetRandomCharacter(enums::EncounterCharacter character_one,
                                               enums::EncounterCharacter character_two);
  void AddEncounterLogRecord(const std::string &content);
  void ProcessConsequenceResult(const Consequence &consequence, SpaceshipStats& spaceship_stats);
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENCOUNTERS_ENCOUNTER_GENERATOR_H_
