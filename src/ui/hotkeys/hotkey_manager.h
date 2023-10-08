#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_

#include <vector>
#include "hotkey.h"
class HotkeyManager {
 public:
  std::vector<Hotkey> hotkeys_;
  HotkeyManager();
  ~HotkeyManager();
  void HandleCommand(int inputValue, Game& game) const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_
