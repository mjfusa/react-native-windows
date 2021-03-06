// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.200316.3

#ifndef WINRT_SampleLibraryCpp_2_H
#define WINRT_SampleLibraryCpp_2_H
#include "winrt/impl/Microsoft.ReactNative.1.h"
#include "winrt/impl/Windows.UI.Composition.1.h"
#include "winrt/impl/Windows.UI.Xaml.1.h"
#include "winrt/impl/Windows.UI.Xaml.Controls.1.h"
#include "winrt/impl/Windows.UI.Xaml.Markup.1.h"
#include "SampleLibraryCpp.1.h"
WINRT_EXPORT namespace winrt::SampleLibraryCpp
{
    struct __declspec(empty_bases) CustomUserControlCpp : SampleLibraryCpp::ICustomUserControlCpp,
        impl::base<CustomUserControlCpp, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DependencyObject>,
        impl::require<CustomUserControlCpp, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IControl5, Windows::UI::Xaml::Controls::IControl7, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControlOverrides6, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::IFrameworkElement6, Windows::UI::Xaml::IFrameworkElement7, Windows::UI::Xaml::IFrameworkElementProtected7, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IUIElement5, Windows::UI::Xaml::IUIElement7, Windows::UI::Xaml::IUIElement8, Windows::UI::Xaml::IUIElement9, Windows::UI::Xaml::IUIElement10, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElementOverrides7, Windows::UI::Xaml::IUIElementOverrides8, Windows::UI::Xaml::IUIElementOverrides9, Windows::UI::Composition::IAnimationObject, Windows::UI::Composition::IVisualElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
    {
        CustomUserControlCpp(std::nullptr_t) noexcept {}
        CustomUserControlCpp(void* ptr, take_ownership_from_abi_t) noexcept : SampleLibraryCpp::ICustomUserControlCpp(ptr, take_ownership_from_abi) {}
        CustomUserControlCpp();
        [[nodiscard]] static auto LabelProperty();
    };
    struct __declspec(empty_bases) ReactPackageProvider : SampleLibraryCpp::IReactPackageProvider,
        impl::require<ReactPackageProvider, Microsoft::ReactNative::IReactPackageProvider>
    {
        ReactPackageProvider(std::nullptr_t) noexcept {}
        ReactPackageProvider(void* ptr, take_ownership_from_abi_t) noexcept : SampleLibraryCpp::IReactPackageProvider(ptr, take_ownership_from_abi) {}
        ReactPackageProvider();
    };
    struct __declspec(empty_bases) XamlMetaDataProvider : Windows::UI::Xaml::Markup::IXamlMetadataProvider
    {
        XamlMetaDataProvider(std::nullptr_t) noexcept {}
        XamlMetaDataProvider(void* ptr, take_ownership_from_abi_t) noexcept : Windows::UI::Xaml::Markup::IXamlMetadataProvider(ptr, take_ownership_from_abi) {}
        XamlMetaDataProvider();
    };
}
#endif
