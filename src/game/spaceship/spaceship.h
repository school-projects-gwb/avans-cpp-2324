#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_

#include <vector>
#include "data_types/coords.h"
#include "game/enums/direction.h"
#include "cargo.h"
#include "game/enums/sector_object_type.h"
#include "sectors/sector.h"
#include "sectors/package_destination_result.h"
#include "spaceship_neighbor_object.h"
#include "spaceship_stats.h"

namespace game {

class SpaceShip {
 public:
  void SetPosition(Coords sector_position, Coords universe_position, std::vector<SpaceshipNeighborObject> neighbor_objects);
  void SetIsAtUniverseEdge(bool is_at_edge);
  void AddCargo(const PackageModel& package, PackageDestinationResult destination_info);

  [[nodiscard]] const Coords& GetPosition() const;
  [[nodiscard]] Coords GetNextMovementPosition(enums::Direction direction) const;
  [[nodiscard]] CargoInfo GetCargoInfo() const;
  SpaceshipStats& GetStats();

  [[nodiscard]] bool HasNeighborOfType(enums::SectorObjectType object_type) const;
  [[nodiscard]] bool HasEnoughWinningPoints() const;
  [[nodiscard]] bool IsDestroyed() const;
  [[nodiscard]] bool IsAtUniverseEdge() const;
  [[nodiscard]] bool CanDeliverCargo() const;
  [[nodiscard]] bool CanPickupCargo() const;
  [[nodiscard]] bool CanViewCargo() const;
  void DeliverCargo();
 private:
  SpaceshipStats spaceship_stats_ = {};
  Cargo cargo_;
  Coords universe_position_;
  Coords sector_position_;
  std::vector<SpaceshipNeighborObject> neighbor_objects_;
  bool at_universe_edge_ = false;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_H_
