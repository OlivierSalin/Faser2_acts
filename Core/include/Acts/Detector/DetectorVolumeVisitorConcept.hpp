// This file is part of the ACTS project.
//
// Copyright (C) 2016 CERN for the benefit of the ACTS project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <utility>

namespace Acts {

namespace Experimental {
class DetectorVolume;
}

template <typename T>
concept DetectorVolumeVisitor = requires(T v) {
  { v(std::declval<const Experimental::DetectorVolume*>()) };
};

template <typename T>
concept MutableDetectorVolumeVisitor = requires(T v) {
  { v(std::declval<Experimental::DetectorVolume*>()) };
};

}  // namespace Acts