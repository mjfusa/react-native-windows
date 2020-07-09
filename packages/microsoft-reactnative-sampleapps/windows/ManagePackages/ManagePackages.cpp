#include "pch.h"
#include "ManagePackages.h"
//#include "ManagePackages.g.cpp"

using namespace winrt;
using namespace winrt::Windows::Foundation::Collections;

namespace RNWManagePackages {

ManagePackages::ManagePackages() {
  HookupCatalog();
}

bool ManagePackages::IsPackageInstalled(std::wstring moduleName) noexcept {
  auto library = LoadPackagedLibrary(moduleName.data(), 0);
  if (library) {
    FreeLibrary(library);
    return true;
  }
  return false;
}

winrt::hstring ManagePackages::FindPackageForUser(std::wstring packageName) noexcept {
  auto _packageManager = PackageManager();
  winrt::hstring name(L"");
  std::wstring estring;
  try {
     auto _currentPackageList =  _packageManager.FindPackagesForUser(estring, packageName);
     std::for_each (begin(_currentPackageList), end(_currentPackageList), [&](Package value) {
         name = value.Id().Name();
    });

     if (name.size()>0) {
      name = _currentPackageList.First().Current().Id().Name();
    } else {
      name = L"ERROR: Package Name not found. App not installed or full Package Family Name not specified.";
    }
  } catch (winrt::hresult_error const &ex) {
    name = ex.message();
  }
  return name;
}

void ManagePackages::PackageInstalling(PackageCatalog const &sender, PackageInstallingEventArgs const &args) {
  if (args.IsComplete()) {
    winrt::hstring result(args.Package().Id().FamilyName().data());
    // fire event to RN
    PackageInstalledEvent(result + L" installed");
  }
}

void ManagePackages::HookupCatalog() {
  m_Catalog = PackageCatalog::OpenForCurrentPackage();
  m_Catalog.PackageInstalling({this, &ManagePackages::PackageInstalling});
}

} // namespace RNWManagePackages
