#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_ENCOUNTER_VIEW_OBJECT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_ENCOUNTER_VIEW_OBJECT_H_

#include "view_object.h"

namespace Interface {
  class EncounterViewObject : public ViewObject {
    char GetDisplayCharacter() override;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_ENCOUNTER_VIEW_OBJECT_H_
