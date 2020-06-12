#pragma once


#include "NativeModules.h"
#include <winrt/Windows.Security.ExchangeActiveSyncProvisioning.h>

using namespace winrt::Windows::Security::ExchangeActiveSyncProvisioning;

namespace DeviceInfo2
{
    REACT_MODULE(SampleComponent);
    struct SampleComponent 
    {
        REACT_METHOD(DeviceModel, L"deviceModel");
        winrt::hstring SampleComponent::DeviceModel() noexcept
        {
            auto info = EasClientDeviceInformation();
            return info.SystemProductName();
        }
    };
}

