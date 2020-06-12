#include "pch.h"
#include "SampleComponent.h"
#include "SampleComponent.g.cpp"
#include <../winrt/Windows.Security.ExchangeActiveSyncProvisioning.h>

//using namespace winrt::Windows::Security::ExchangeActiveSyncProvisioning;

namespace winrt::DeviceInfo2::implementation
{
    REACT_METHOD(DeviceModel, L"deviceModel");
    winrt::hstring SampleComponent::DeviceModel() noexcept
    {
        //auto info = EasClientDeviceInformation();
        return L"";//info.SystemProductName();
    }
}
