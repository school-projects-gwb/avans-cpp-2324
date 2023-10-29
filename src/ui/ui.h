#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_

#include "game_manager.h"
#include "ui/view_objects/object_character_factory.h"
#include "ansi_colors.h"

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
  void ShowPackageInfo() const;
  [[nodiscard]] static std::string GetFormattedCoordsString(game::Coords coords);
  static void PrintFormattedRowNumber(int row_number);
  static void PrintFormattedColumnHeader(int total_column_count);
  void ShowEncounter() const;
  static void PrintToOutput(const std::string &content, const std::string& color = ANSI_COLOR_RESET);
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_UI_H_
