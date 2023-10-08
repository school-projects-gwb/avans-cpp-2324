#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_

#include <vector>
#include "hotkey.h"
class HotkeyManager {
 private:
  std::vector<Hotkey> hotkeys_;
 public:
  HotkeyManager();
  ~HotkeyManager();
  const void HandleCommand(int key, Game& game);
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_
