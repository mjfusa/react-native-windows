// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.190730.2

#ifndef WINRT_NativeUICtrl_2_H
#define WINRT_NativeUICtrl_2_H
#include "winrt/impl/Microsoft.ReactNative.1.h"
#include "NativeUICtrl.1.h"
namespace winrt::NativeUICtrl
{
    struct __declspec(empty_bases) ReactPackageProvider : NativeUICtrl::IReactPackageProvider,
        impl::require<ReactPackageProvider, Microsoft::ReactNative::IReactPackageProvider>
    {
        ReactPackageProvider(std::nullptr_t) noexcept {}
        ReactPackageProvider(void* ptr, take_ownership_from_abi_t) noexcept : NativeUICtrl::IReactPackageProvider(ptr, take_ownership_from_abi) {}
        ReactPackageProvider();
    };
}
#endif
