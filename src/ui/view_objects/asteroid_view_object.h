#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_ASTEROID_VIEW_OBJECT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_ASTEROID_VIEW_OBJECT_H_

#include "view_object.h"

namespace interface {
  class AsteroidViewObject : public ViewObject {
    char GetDisplayCharacter() const override;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_ASTEROID_VIEW_OBJECT_H_
