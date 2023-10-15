#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_

#include <vector>
#include "data/coords.h"
#include "data/direction.h"
#include "cargo.h"
#include "sectors/sector_object_type.h"
#include "sectors/sector.h"

namespace game {
  class SpaceShip {
   public:
    void SetPosition(Coords new_position, std::vector<SectorObjectType> neighbor_objects);
    void SetIsAtUniverseEdge(bool is_at_edge);

    const Coords &GetPosition() const;
    Coords GetNextMovementPosition(Direction direction) const;

    bool HasNeighborOfType(SectorObjectType object_type) const;
    bool HasCargo() const;
    bool CanDeliverCargo() const;
    bool IsAtUniverseEdge() const;
   private:
    int damage_points_ = 0;
    int winning_points = 0;
    Cargo cargo_;
    Coords position_;
    std::vector<SectorObjectType> neighbor_objects_;
    bool at_universe_edge = false;
  };
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
