#include "asteroid_view_object.h"
#include "ansi_colors.h"

namespace interface {

char AsteroidViewObject::GetDisplayCharacter() const {
  return 'O';
}

const std::string AsteroidViewObject::GetDisplayColor() const {
  return ANSI_COLOR_YELLOW;
}

}