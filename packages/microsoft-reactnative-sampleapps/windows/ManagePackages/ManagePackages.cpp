#include "pch.h"
#include "ManagePackages.h"
//#include "ManagePackages.g.cpp"

namespace RNWManagePackages
{
    winrt::hstring ManagePackages::FindPackageForUser(std::wstring packageName) noexcept {
    auto _packageManager = PackageManager();
      Package _currentPackage({nullptr});
      winrt::hstring name(L"");
      std::wstring estring;
      try {
        _currentPackage = _packageManager.FindPackageForUser(estring, packageName);
        if (_currentPackage) {
          name = _currentPackage.Id().Name();
        } else {
          name = L"ERROR: Package Name not found. App not installed or full Package Family Name not specified.";
        }
      } catch (winrt::hresult_error const &ex) {
        name = ex.message();
      }
      return name;
    }

    void ManagePackages::PackageInstalling(PackageCatalog const &sender, PackageInstallingEventArgs const &args)
    {
       if (args.IsComplete()) {
          // fire event to RN
          //WriteToTextBox("PackageCatalog - Done installing package");
        //WriteToTextBox(args->Package->Id->FamilyName->ToString());
      }
    }

    void ManagePackages::HookupCatalog()
    {
       auto catalog = PackageCatalog::OpenForCurrentPackage();
      catalog.PackageInstalling({this, &ManagePackages::PackageInstalling});
    }




}
