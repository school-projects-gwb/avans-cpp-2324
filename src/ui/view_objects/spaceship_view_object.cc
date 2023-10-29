#include "spaceship_view_object.h"
#include "ansi_colors.h"

namespace interface {

char SpaceshipViewObject::GetDisplayCharacter() const {
  return 'P';
}

const std::string SpaceshipViewObject::GetDisplayColor() const {
  return ANSI_COLOR_BLUE;
}

}
