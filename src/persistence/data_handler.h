#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_DATA_HANDLER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_DATA_HANDLER_H_

#include <sqlite3.h>
#include "data_models/package_model.h"
#include "game/enums/sector_object_type.h"
#include "data_models/encounter_model.h"

namespace persistence {

class DataHandler {
 public:
  [[nodiscard]] std::vector<game::EncounterModel> GetEncounters() const;
  [[nodiscard]] std::vector<game::PackageModel> GetPackages() const;
  static std::vector<game::EncounterModel,
  std::allocator<game::EncounterModel>>::iterator FindEncounterByID(std::vector<game::EncounterModel> &encounters,int id) ;
  static game::Consequence CreateConsequenceFromRow(sqlite3_stmt *statement) ;
  static std::string GetStringColumn(sqlite3_stmt *statement, int column_index) ;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_DATA_HANDLER_H_
