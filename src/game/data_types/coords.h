#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_COORDS_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_COORDS_H_

namespace game {
  struct Coords {
    int pos_x;
    int pos_y;

    bool operator==(const Coords& other) const {
      return pos_x == other.pos_x && pos_y == other.pos_y;
    }
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_COORDS_H_
