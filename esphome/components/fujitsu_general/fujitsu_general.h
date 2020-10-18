#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "esphome/components/climate_ir/climate_ir.h"

namespace esphome {
namespace fujitsu_general {

class FujitsuGeneralClimate : public climate_ir::ClimateIR {
 public:
  FujitsuGeneralClimate();

 protected:
  /// Transmit via IR the state of this climate controller.
  void transmit_state() override;
  /// Transmit via IR power off command.
  void transmit_off_();
  /// Handle received IR Buffer
  bool on_receive(remote_base::RemoteReceiveData data) override;
  bool parse_state_frame_(const uint8_t remote_state[]);

  bool power_{false};
};

}  // namespace fujitsu_general
}  // namespace esphome
