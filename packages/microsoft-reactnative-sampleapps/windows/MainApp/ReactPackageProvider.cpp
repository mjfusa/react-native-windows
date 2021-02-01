// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "ReactPackageProvider.h"

#include "NativeModules.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::MainApp::implementation {

//===========================================================================
// ReactPackageProvider implementation
//===========================================================================

void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept {
  AddAttributedModules(packageBuilder);
}

} // namespace winrt::MainApp::implementation
