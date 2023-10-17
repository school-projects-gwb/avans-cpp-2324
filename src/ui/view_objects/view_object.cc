#include <iostream>
#include "view_object.h"

namespace interface {
  char ViewObject::GetDisplayCharacter() const {
    return '.';
  }

  void ViewObject::Print() const {
    std::cout << GetDisplayCharacter() << " ";
  }
}