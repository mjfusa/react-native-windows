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
      ManagePackages::ManagePackages();

      REACT_METHOD(FindPackageForUser, L"findPackageForUser");
      winrt::hstring ManagePackages::FindPackageForUser(std::wstring packageName) noexcept;

      REACT_METHOD(IsPackageInstalled, L"isPackageInstalled");
      bool ManagePackages::IsPackageInstalled(std::wstring moduleName) noexcept;

      void ManagePackages::HookupCatalog();
      void ManagePackages::PackageInstalling(PackageCatalog const &sender, PackageInstallingEventArgs const &args);

      REACT_EVENT(PackageInstalledEvent);
      std::function<void(winrt::hstring)> PackageInstalledEvent;

    private:
      PackageCatalog m_Catalog=nullptr;


    };
}

