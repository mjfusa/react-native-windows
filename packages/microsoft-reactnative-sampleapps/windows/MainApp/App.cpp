#include "pch.h"

#include "App.h"

#include "AutolinkedNativeModules.g.h"
#include "ReactPackageProvider.h"
#include <winrt/NativeModule.h>
#include <ReactNotificationService.h>

#include "winrt/Windows.ApplicationModel.Background.h"

using namespace winrt::MainApp;
using namespace winrt::MainApp::implementation;
using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::ApplicationModel;

using namespace winrt::Windows::ApplicationModel::Background;
using namespace winrt::Windows::ApplicationModel::Activation;

namespace winrt::MainApp::implementation {
static const ReactNotificationId<int> backgroundNotificationId(L"NativeModuleClass", L"BackgroundNotification");

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

  RegisterAutolinkedNativeModulePackages(PackageProviders()); // Includes any autolinked modules

  PackageProviders().Append(make<ReactPackageProvider>()); // Includes all modules in this project
  PackageProviders().Append(winrt::NativeModule::ReactPackageProvider()); // Includes all modules in this project

  InitializeComponent();

}

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used such as when the application is launched to open a specific file.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(activation::LaunchActivatedEventArgs const& e)
{
    super::OnLaunched(e);

    Frame rootFrame = Window::Current().Content().as<Frame>();
    rootFrame.Navigate(xaml_typename<MainApp::MainPage>(), box_value(e.Arguments()));
}

/// <summary>
/// Invoked when application execution is being suspended.  Application state is saved
/// without knowing whether the application will be terminated or resumed with the contents
/// of memory still intact.
/// </summary>
/// <param name="sender">The source of the suspend request.</param>
/// <param name="e">Details about the suspend request.</param>
void App::OnSuspending([[maybe_unused]] IInspectable const& sender, [[maybe_unused]] SuspendingEventArgs const& e)
{
    // Save application state and stop any background activity
}

/// <summary>
/// Invoked when Navigation to a certain page fails
/// </summary>
/// <param name="sender">The Frame which failed navigation</param>
/// <param name="e">Details about the navigation failure</param>
void App::OnNavigationFailed(IInspectable const&, NavigationFailedEventArgs const& e)
{
    throw hresult_error(E_FAIL, hstring(L"Failed to load Page ") + e.SourcePageType().Name);
}

void App::OnBackgroundActivated(winrt::Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs const& args) {
  auto taskInstance = args.TaskInstance();
  BackgroundTaskDeferral deferral = taskInstance.GetDeferral();
  auto taskName = winrt::to_hstring(taskInstance.Task().Name());

    auto rns = InstanceSettings().Notifications();
    rns.SendNotification(backgroundNotificationId.Handle(), box_value(taskName), box_value(0));

  deferral.Complete();

  }

}
