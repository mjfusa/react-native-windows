// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once
#include "winrt/Microsoft.ReactNative.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::MainApp::implementation {

struct ReactPackageProvider : winrt::implements<ReactPackageProvider, IReactPackageProvider> {
 public: // IReactPackageProvider
  void CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept;
};

} // namespace winrt::MainApp::implementation
