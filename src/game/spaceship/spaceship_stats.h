#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_STATS_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_STATS_H_

namespace game {

class SpaceshipStats {
 public:
  int AppendWinningPoints(int amount);
  int AppendDamagePoints(int amount);
  int GetWinningPoints() const;
  int GetDamagePoints() const;
 private:
  int damage_points_ = 0;
  int winning_points_ = 0;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_SPACESHIP_STATS_H_
