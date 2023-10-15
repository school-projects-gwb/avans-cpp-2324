#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_CARGO_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_CARGO_H_

#include "cargo_info.h"
#include "data_models/package.h"
#include "sectors/package_destination_result.h"

namespace game {

class Cargo {
 public:
  void AddCargo(const Package& package, PackageDestinationResult destination_info);
  void UpdateStatus(bool is_in_transit);
  CargoInfo GetCargoInfo() const;
  bool GetIsInTransit() const;
 private:
  Shipment current_shipment_ = {};
  bool is_in_transit_ = false;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_SPACESHIP_CARGO_H_
