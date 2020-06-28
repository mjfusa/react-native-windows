#pragma once


#include "NativeModules.h"
#include <winrt/Windows.Management.Deployment.h>
#include <winrt/Windows.ApplicationModel.h>

//using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Management::Deployment;
using namespace winrt::Windows::ApplicationModel;

namespace RNWManagePackages
{
    REACT_MODULE(ManagePackages);
    struct ManagePackages 
    {
      REACT_METHOD(FindPackageForUser, L"findPackageForUser");
      winrt::hstring ManagePackages::FindPackageForUser(std::wstring packageName) noexcept;

      void ManagePackages::HookupCatalog();
      void ManagePackages::PackageInstalling(PackageCatalog const &sender, PackageInstallingEventArgs const &args);

    private:


    };
}

