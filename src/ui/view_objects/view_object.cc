#include <iostream>
#include "view_object.h"

namespace interface {
  char ViewObject::GetDisplayCharacter() {
    return '.';
  }

  void ViewObject::Print() {
    std::cout << GetDisplayCharacter() << " ";
  }
}