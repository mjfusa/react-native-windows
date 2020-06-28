// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "App.h"
#include <CppWinRTIncludes.h>
#include <ReactPackageProvider.h>
#include <ReactPropertyBag.h>

#include <winrt/PackageInventory.h>
#include <winrt/RNWManagePackages.h>

#include <headers/DeviceInfo2.h>
#include <headers/SampleLibraryCpp.h>

using namespace winrt;
using namespace xaml;
using namespace xaml::Controls;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;

namespace winrt::SampleAppCpp::implementation {

/// <summary>
/// Initializes the singleton application object.  This is the first line of
/// authored code executed, and as such is the logical equivalent of main() or
/// WinMain().
/// </summary>
App::App() noexcept {
#if BUNDLE
  JavaScriptBundleFile(L"index.windows");
  InstanceSettings().UseWebDebugger(false);
  InstanceSettings().UseFastRefresh(false);
#else
  JavaScriptMainModuleName(L"index");
  InstanceSettings().UseWebDebugger(true);
  InstanceSettings().UseFastRefresh(true);
#endif

#if _DEBUG
  InstanceSettings().UseDeveloperSupport(true);
#else
  InstanceSettings().UseDeveloperSupport(false);
#endif

  ReactPropertyBag::Set(InstanceSettings().Properties(), ReactPropertyId<int>{L"Prop1"}, 42);
  ReactPropertyBag::Set(InstanceSettings().Properties(), ReactPropertyId<hstring>{L"Prop2"}, L"Hello World!");

  PackageProviders().Append(make<ReactPackageProvider>()); // Includes all modules in this project
  PackageProviders().Append(winrt::PackageInventory::ReactPackageProvider());
  PackageProviders().Append(winrt::RNWManagePackages::ReactPackageProvider());

    // Optional Native Module
  if (IsPackageInstalled(L"DeviceInfo2.dll"))
    PackageProviders().Append(winrt::DeviceInfo2::ReactPackageProvider());

    // Optional Native UI Module
  if (IsPackageInstalled(L"SampleLibraryCpp.dll"))
    PackageProviders().Append(winrt::SampleLibraryCpp::ReactPackageProvider());

  
  InitializeComponent();
}

bool App::IsPackageInstalled(std::wstring_view moduleName) {
  auto library = LoadPackagedLibrary(moduleName.data(), 0);
  if (library) {
    FreeLibrary(library);
    return true;
  }
  return false;
}

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used such as when the application is launched to open a specific file.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(LaunchActivatedEventArgs const &e) {
  super::OnLaunched(e);
  Frame rootFrame = Window::Current().Content().as<Frame>();
  rootFrame.Navigate(xaml_typename<MainPage>(), box_value(e.Arguments()));
}

} // namespace winrt::SampleAppCpp::implementation
