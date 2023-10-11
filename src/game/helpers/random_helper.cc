#include "random_helper.h"

namespace Game {
  int RandomHelper::GenerateRandomInt(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator_);
  }

  RandomHelper &RandomHelper::GetInstance() {
    static RandomHelper instance;
    return instance;
  }

  RandomHelper::RandomHelper() {
    std::random_device rd;
    generator_.seed(rd());
  }
}