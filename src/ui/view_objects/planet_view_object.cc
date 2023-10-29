#include "planet_view_object.h"
#include "ansi_colors.h"

namespace interface {

char PlanetViewObject::GetDisplayCharacter() const {
  return '@';
}

const std::string PlanetViewObject::GetDisplayColor() const {
  return ANSI_COLOR_GREEN;
}

}
