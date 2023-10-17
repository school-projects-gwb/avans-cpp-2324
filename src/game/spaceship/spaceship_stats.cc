#include "spaceship_stats.h"

namespace game {

void SpaceshipStats::AppendWinningPoints(int amount) {
  winning_points_ += amount;
}

void SpaceshipStats::AppendDamagePoints(int amount) {
  damage_points_ += amount;
}

void SpaceshipStats::ResetDamagePoints() {
  damage_points_ = 0;
}

int SpaceshipStats::GetWinningPoints() const {
  return winning_points_;
}

int SpaceshipStats::GetDamagePoints() const {
  return damage_points_;
}

}
