#include "pch.h"
#include "ManagePackages.h"
#include "ManagePackages.g.cpp"
#include <../winrt/Windows.Security.ExchangeActiveSyncProvisioning.h>

//using namespace winrt::Windows::Security::ExchangeActiveSyncProvisioning;

namespace winrt::RNWManagePackages::implementation
{
    REACT_METHOD(DeviceModel, L"deviceModel");
    winrt::hstring SampleComponent::DeviceModel() noexcept
    {
        //auto info = EasClientDeviceInformation();
        return L"";//info.SystemProductName();
    }
}
