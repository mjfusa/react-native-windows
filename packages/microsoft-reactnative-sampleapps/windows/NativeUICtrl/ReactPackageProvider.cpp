#include "pch.h"
#include "ReactPackageProvider.h"
#include "ReactPackageProvider.g.cpp"

#include <ModuleRegistration.h>

// NOTE: You must include the headers of your native modules here in
// order for the AddAttributedModules call below to find them.
#include "CustomUserControlViewManager.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::NativeUICtrl::implementation {

    void ReactPackageProvider::CreatePackage(IReactPackageBuilder const& packageBuilder)
        noexcept {
        packageBuilder.AddViewManager(
            L"CustomUserControlViewManager", []() { return winrt::make<CustomUserControlViewManager>(); });
    }

}