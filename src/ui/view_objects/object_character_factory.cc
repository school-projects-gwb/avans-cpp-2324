#include <memory>
#include "object_character_factory.h"
#include "view_object.h"
#include "encounter_view_object.h"
#include "planet_view_object.h"
#include "asteroid_view_object.h"
#include "spaceship_view_object.h"

using namespace game;

namespace interface {
  std::shared_ptr<ViewObject> ViewObjectFactory::GetObjectCharacter(enums::SectorObjectType object_type) const {
    switch (object_type) {
      case enums::SectorObjectType::Asteroid:return std::make_shared<AsteroidViewObject>();
      case enums::SectorObjectType::Planet:return std::make_shared<PlanetViewObject>();
      case enums::SectorObjectType::Encounter:return std::make_shared<EncounterViewObject>();
      case enums::SectorObjectType::Spaceship:return std::make_shared<SpaceshipViewObject>();
      default:return std::make_shared<ViewObject>();
    }
  }
}
