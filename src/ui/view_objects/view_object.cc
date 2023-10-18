#include <iostream>
#include "view_object.h"
#include "logger.h"

namespace interface {
  char ViewObject::GetDisplayCharacter() const {
    return '.';
  }

  const std::string ViewObject::GetPrintContent() const {
    return std::string(1, GetDisplayCharacter()) + " ";
  }
}