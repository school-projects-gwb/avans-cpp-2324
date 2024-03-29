#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_ENCOUNTER_VIEW_OBJECT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_ENCOUNTER_VIEW_OBJECT_H_

#include "view_object.h"

namespace interface {

class EncounterViewObject : public ViewObject {
  [[nodiscard]] char GetDisplayCharacter() const override;
  [[nodiscard]] const std::string GetDisplayColor() const override;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_ENCOUNTER_VIEW_OBJECT_H_
