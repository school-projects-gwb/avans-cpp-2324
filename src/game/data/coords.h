#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_COORDS_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_COORDS_H_

namespace Game {
  struct Coords {
    int pos_x_;
    int pos_y_;

    bool operator==(const Coords& other) const {
      return pos_x_ == other.pos_x_ && pos_y_ == other.pos_y_;
    }
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_COORDS_H_
