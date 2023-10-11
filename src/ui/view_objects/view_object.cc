#include <iostream>
#include "view_object.h"

namespace Interface {
  char ViewObject::GetDisplayCharacter() {
    return '.';
  }

  void ViewObject::Print() {
    std::cout << GetDisplayCharacter() << " ";
  }
}