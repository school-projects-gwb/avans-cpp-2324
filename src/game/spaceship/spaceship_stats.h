#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_STATS_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_STATS_H_

namespace game {

class SpaceshipStats {
 public:
  void AppendWinningPoints(int amount);
  void AppendDamagePoints(int amount);
  void ResetDamagePoints();
  [[nodiscard]] int GetDamagePoints() const;
  bool IsDestroyed() const;
  bool HasEnoughWinningPoints() const;
 private:
  const int points_to_die_ = 200;
  const int points_to_win_ = 10;
  int damage_points_ = 0;
  int winning_points_ = 0;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_STATS_H_
