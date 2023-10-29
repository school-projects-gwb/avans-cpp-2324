#include <iostream>
#include "view_object.h"
#include "logger.h"
#include "ansi_colors.h"

namespace interface {

char ViewObject::GetDisplayCharacter() const {
  return '.';
}

const std::string ViewObject::GetPrintContent() const {
  return std::string(1, GetDisplayCharacter()) + " ";
}

const std::string ViewObject::GetDisplayColor() const {
  return ANSI_COLOR_RESET;
}

}