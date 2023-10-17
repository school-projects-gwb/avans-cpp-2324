#include "spaceship_stats.h"
#include <iostream>

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

int SpaceshipStats::GetDamagePoints() const {
  return damage_points_;
}

bool SpaceshipStats::IsDestroyed() const {
  return damage_points_ >= points_to_die_;
}

bool SpaceshipStats::HasEnoughWinningPoints() const {
  return winning_points_ >= points_to_win_;
}

}
