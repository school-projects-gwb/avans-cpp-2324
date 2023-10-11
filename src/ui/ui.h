#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_

#include "command_center.h"
#include "ui/view_objects/object_character_factory.h"

namespace Interface {
  class Ui {
   public:
    explicit Ui(const Game::CommandCenter &game);
    void UpdateUi(Game::GameState state) const;
    void ShowSector() const;
   private:
    const ViewObjectFactory view_object_factory_;
    const Game::CommandCenter &game_;
    void ShowScan() const;
  };
}
#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
