#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_

#include <vector>
#include "action.h"

namespace interface {

class ActionRegistry {
 public:
  std::vector<UserAction> hotkeys_;
  ActionRegistry();
  ~ActionRegistry();
  // Delete other operations
  ActionRegistry(const ActionRegistry&) = delete;
  ActionRegistry& operator=(const ActionRegistry&) = delete;
  ActionRegistry(ActionRegistry&&) = delete;
  ActionRegistry& operator=(ActionRegistry&&) = delete;

  void HandleCommand(int input_value, game::GameManager &game) const;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_HOTKEYS_HOTKEY_MANAGER_H_
