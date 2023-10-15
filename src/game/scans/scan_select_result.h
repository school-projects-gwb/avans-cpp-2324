#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SCAN_SELECT_RESULT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SCAN_SELECT_RESULT_H_

namespace game {
  struct ScanSelectResult {
    bool is_valid_ = false;
    int row_number_;
    int col_number_;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_ENTITIES_SCAN_SELECT_RESULT_H_
