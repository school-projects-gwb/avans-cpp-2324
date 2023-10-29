#include "encounter_view_object.h"
#include "ansi_colors.h"

namespace interface {

char EncounterViewObject::GetDisplayCharacter() const {
  return '*';
}

const std::string EncounterViewObject::GetDisplayColor() const {
  return ANSI_COLOR_RED;
}

}
