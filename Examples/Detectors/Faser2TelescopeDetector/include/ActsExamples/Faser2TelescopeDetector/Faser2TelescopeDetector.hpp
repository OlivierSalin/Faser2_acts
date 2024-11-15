// This file is part of the ACTS project.
//
// Copyright (C) 2016 CERN for the benefit of the ACTS project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include "Acts/Definitions/Units.hpp"
#include "Acts/Utilities/Logger.hpp"
#include "ActsExamples/Utilities/Options.hpp"

#include <array>
#include <memory>
#include <utility>
#include <vector>

using namespace Acts::UnitLiterals;

namespace Acts {
class TrackingGeometry;
class IMaterialDecorator;
}  // namespace Acts

namespace ActsExamples {
class IContextDecorator;
}  // namespace ActsExamples

namespace ActsExamples::Faser2Telescope {

class Faser2TelescopeDetectorElement;
class Faser2TelescopeG4DetectorConstruction;

struct Faser2TelescopeDetector {
  using DetectorElement = ActsExamples::Faser2Telescope::Faser2TelescopeDetectorElement;
  using DetectorElementPtr = std::shared_ptr<DetectorElement>;
  using DetectorStore = std::vector<DetectorElementPtr>;

  using ContextDecorators =
      std::vector<std::shared_ptr<ActsExamples::IContextDecorator>>;
  using TrackingGeometryPtr = std::shared_ptr<const Acts::TrackingGeometry>;

  struct Config {
    std::vector<double> positions{{0, 30, 60, 120, 150, 180}};
    std::array<double, 2> offsets{{0, 0}};
    std::vector<double> stereos{{0, 0, 0, 0, 0, 0}};
    std::array<double, 2> bounds{{25, 100}};
    double thickness{80_um};
    int surfaceType{0};
    int binValue{2};
    std::vector<double> boundsX{{100, 300, 600, 1020, 1500, 180}};
    std::vector<double> boundsY{{150, 310, 620, 1220, 150, 180}};
    std::vector<int> Type_surf{{0,0,0,0,0,0}};
  };

  Config config;
  /// The store of the detector elements (lifetime: job)
  DetectorStore detectorStore;

  std::pair<TrackingGeometryPtr, ContextDecorators> finalize(
      const Config& cfg,
      const std::shared_ptr<const Acts::IMaterialDecorator>& mdecorator);
};

}  // namespace ActsExamples::Faser2Telescope
