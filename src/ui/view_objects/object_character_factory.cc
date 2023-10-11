#include <memory>
#include "object_character_factory.h"
#include "view_object.h"
#include "encounter_view_object.h"
#include "planet_view_object.h"
#include "asteroid_view_object.h"
#include "spaceship_view_object.h"

std::shared_ptr<ViewObject> ViewObjectFactory::GetObjectCharacter(SectorObjectType object_type) const {
  switch (object_type) {
    case SectorObjectType::Asteroid:
      return std::make_shared<AsteroidViewObject>();
    case SectorObjectType::Planet:
      return std::make_shared<PlanetViewObject>();
    case SectorObjectType::Encounter:
      return std::make_shared<EncounterViewObject>();
    case SectorObjectType::Spaceship:
      return std::make_shared<SpaceshipViewObject>();
    default:
      return std::make_shared<ViewObject>();
  }
}
