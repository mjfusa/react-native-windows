#include "pch.h"
#include INCLUDE_FILE_X(MODULE.h)

#include "ReactNotificationService.h"
#include <winrt/Windows.Security.ExchangeActiveSyncProvisioning.h>
#include <winrt/Windows.ApplicationModel.Background.h>
#include <CppWinRTIncludes.h>
#include <winrt/base.h>

using namespace NAMESPACE; 
using namespace winrt;
using namespace Microsoft::ReactNative;
using namespace Windows::Security::ExchangeActiveSyncProvisioning;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Background;

winrt::hstring MODULE::DeviceModel() noexcept {
    auto info = EasClientDeviceInformation();
    return info.SystemProductName();
}

// Test signaling of background task with App Trigger
void MODULE::TestFireBackgroundTask() noexcept {
    TestFireBackgroundTaskAsync();
}

IAsyncAction MODULE::TestFireBackgroundTaskAsync() noexcept 
{
    auto result = _AppTrigger.RequestAsync();
    co_return;
}

void MODULE::RegisterNativeJsTaskHook(std::string const& str_taskName) noexcept
{
    registerNativeJsTaskHook(str_taskName);
}


IAsyncAction MODULE::registerNativeJsTaskHook(std::string const& str_taskName) noexcept
{
    auto taskName = str_taskName;

    auto accessStatus = co_await BackgroundExecutionManager::RequestAccessAsync();
    if ((BackgroundAccessStatus::AlwaysAllowed == accessStatus) ||
        (BackgroundAccessStatus::AllowedSubjectToSystemPolicy == accessStatus))
    {

        auto taskRegistrations{ BackgroundTaskRegistration::AllTasks() };

        for (const auto& taskRegistration : taskRegistrations)
        {
            // Assuming one background task. Just un-register all tasks when registering a new one.
            // This prevents needing to worry about the name of the task changing and leaving zombie tasks.
            taskRegistration.Value().Unregister(false);
        }

        BackgroundTaskBuilder builder;
        builder.Name(winrt::to_hstring(taskName));
        //builder.SetTrigger(_AppTrigger); // Test signaling of background task with App Trigger
        builder.SetTrigger(SystemTrigger(SystemTriggerType::TimeZoneChange, false));
        auto registration = builder.Register();
    }
    
    co_return;
}

void MODULE::Initialize(winrt::Microsoft::ReactNative::ReactContext const& reactContext) noexcept
{
	m_reactContext = reactContext;
    //_AppTrigger = ApplicationTrigger(); // Test signaling of background task with App Trigger

    const ReactNotificationId<int> backgroundNotification{ L"NativeModuleClass", L"BackgroundNotification" };

    m_reactContext.Notifications().Subscribe(backgroundNotification, [this](IInspectable const& sender, ReactNotificationArgs<int> const& args)
        {
            hstring taskName = unbox_value<winrt::hstring>(sender);
            m_reactContext.CallJSFunction(L"AppRegistry", L"startHeadlessTask", 1, taskName);

        }); 
}

