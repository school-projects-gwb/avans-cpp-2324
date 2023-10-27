#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_PACKAGE_MODEL_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_PACKAGE_MODEL_H_

#include <string>
#include "helpers/random_helper.h"

namespace game {

class PackageModel {
 public:
  std::string content_description_;
  std::string destination_description_;
  static PackageModel GetRandomPackage(std::vector<PackageModel> packages) {
    auto random_int = RandomHelper::GetInstance().GenerateRandomInt(0, packages.size()-1);
    return packages.at(random_int);
  }
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_MODELS_PACKAGE_MODEL_H_
