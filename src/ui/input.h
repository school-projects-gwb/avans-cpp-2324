#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_

#include "game.h"
#include "ui/hotkeys/hotkey_manager.h"
class Input {
 private:
  HotkeyManager hotkey_manager_;
  void ShowAllowedCommands(Game& game) const;
 public:
  Input();
  void HandleInput(Game& game) const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_INPUT_H_