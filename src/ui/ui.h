#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_

#include "game_manager.h"
#include "ui/view_objects/object_character_factory.h"

namespace interface {
  class Ui {
   public:
    explicit Ui(const game::GameManager &game);
    void UpdateUi(game::enums::MainGameState state, game::enums::SubGameState sub_game_state) const;
    void ShowSector() const;
   private:
    const ViewObjectFactory view_object_factory_;
    const game::GameManager &game_;
    void ShowScan() const;
    void ShowPackagePickupBlocked() const;
    void ShowPackageInfo() const;
    std::string GetFormattedCoordsString(game::Coords coords) const;
    void ShowPackageDeliverySuccess() const;
  };
}
#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
