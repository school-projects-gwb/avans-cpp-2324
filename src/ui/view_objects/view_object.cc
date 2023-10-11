#include <iostream>
#include "view_object.h"

char ViewObject::GetDisplayCharacter() {
  return '.';
}

void ViewObject::Print() {
  std::cout << GetDisplayCharacter() << " ";
}