// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "pch.h"

#include "ReactPackageProvider.h"
#include "ReactPackageProvider.g.cpp"

//#include <ModuleRegistration.h>
#include "ManagePackages.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::RNWManagePackages::implementation
{
    void ReactPackageProvider::CreatePackage(IReactPackageBuilder const& packageBuilder) noexcept
    {
        AddAttributedModules(packageBuilder);
    }
}
