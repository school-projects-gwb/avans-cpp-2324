#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_

#include "game.h"
#include "ui/view_objects/object_character_factory.h"

class Ui {
 public:
  explicit Ui(const Game& game);
  void UpdateUi(GameState state) const;
  void ShowSector() const;
 private:
  const ViewObjectFactory view_object_factory_;
  const Game& game_;
  void ShowScan() const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
