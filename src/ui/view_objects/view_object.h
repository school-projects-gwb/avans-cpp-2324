#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_VIEW_OBJECT_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_VIEW_OBJECT_H_

#include <string>

namespace interface {
  class ViewObject {
   public:
    virtual char GetDisplayCharacter() const;
    virtual const std::string GetPrintContent() const;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_UI_VIEW_OBJECTS_VIEW_OBJECT_H_
