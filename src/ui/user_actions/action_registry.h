#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_

#include <vector>
#include "action.h"
class ActionRegistry {
 public:
  std::vector<UserAction> hotkeys_;
  ActionRegistry();
  ~ActionRegistry();
  void HandleCommand(int inputValue, Game& game) const;
};

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_
