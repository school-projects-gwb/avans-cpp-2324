#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_

#include "game.h"
class Ui {
 private:
  const Game& game_;
 public:
  explicit Ui(const Game& game);
  void ShowScan() const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
