#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_OBJECT_CHARACTER_FACTORY_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_OBJECT_CHARACTER_FACTORY_H_

#include "sectors/sector_object_type.h"
#include "view_object.h"

namespace interface {
  class ViewObjectFactory {
   public:
    std::shared_ptr<ViewObject> GetObjectCharacter(game::SectorObjectType object_type) const;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_OBJECT_CHARACTER_FACTORY_H_
