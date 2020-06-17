#pragma once


#include "NativeModules.h"
#include <winrt/Windows.Security.ExchangeActiveSyncProvisioning.h>

using namespace winrt::Windows::Security::ExchangeActiveSyncProvisioning;

namespace PackageInventory
{
    REACT_MODULE(OptionalPackages);
    struct OptionalPackages 
    {
      REACT_METHOD(IsPackageInstalled, L"isPackageInstalled");
      bool OptionalPackages::IsPackageInstalled(std::wstring moduleName) noexcept
        {
        auto library = LoadPackagedLibrary(moduleName.data(), 0);
        if (library) {
          FreeLibrary(library);
          return true;
        }
        return false;
      }
    };
}

