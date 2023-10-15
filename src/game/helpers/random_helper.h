#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_HELPERS_RANDOM_HELPER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_HELPERS_RANDOM_HELPER_H_

#include <random>

namespace game {
  class RandomHelper {
   public:
    static RandomHelper& GetInstance();
    int GenerateRandomInt(int min, int max);
   private:
    RandomHelper();
    std::default_random_engine generator_;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_HELPERS_RANDOM_HELPER_H_
