#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_

#include <vector>
#include "data/coords.h"
#include "data/direction.h"
#include "cargo.h"
#include "sectors/sector_object_type.h"
#include "sectors/sector.h"
#include "sectors/package_destination_result.h"
#include "spaceship_neighbor_object.h"

namespace game {
  class SpaceShip {
   public:
    void SetPosition(Coords sector_position, Coords universe_position, std::vector<SpaceshipNeighborObject> neighbor_objects);
    void SetIsAtUniverseEdge(bool is_at_edge);
    void AddCargo(const Package& package, PackageDestinationResult destination_info);

    const Coords &GetPosition() const;
    Coords GetNextMovementPosition(Direction direction) const;
    CargoInfo GetCargoInfo() const;

    bool HasNeighborOfType(SectorObjectType object_type) const;
    bool IsAtUniverseEdge() const;
    bool CanDeliverCargo() const;
    bool CanPickupCargo() const;
    bool CanViewCargo() const;
    void DeliverCargo();
   private:
    int damage_points_ = 0;
    int winning_points = 0;
    Cargo cargo_;
    Coords universe_position_;
    Coords sector_position_;
    std::vector<SpaceshipNeighborObject> neighbor_objects_;
    bool at_universe_edge = false;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
