// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.200316.3

#ifndef WINRT_SampleLibraryCpp_H
#define WINRT_SampleLibraryCpp_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.200316.3"), "Mismatched C++/WinRT headers.");
#include "winrt/impl/Microsoft.ReactNative.2.h"
#include "winrt/impl/Windows.UI.Composition.2.h"
#include "winrt/impl/Windows.UI.Xaml.2.h"
#include "winrt/impl/Windows.UI.Xaml.Controls.2.h"
#include "winrt/impl/Windows.UI.Xaml.Markup.2.h"
#include "SampleLibraryCpp.2.h"
namespace winrt::impl
{
    template <typename D> WINRT_IMPL_AUTO(hstring) consume_SampleLibraryCpp_ICustomUserControlCpp<D>::Label() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(SampleLibraryCpp::ICustomUserControlCpp)->get_Label(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_SampleLibraryCpp_ICustomUserControlCpp<D>::Label(param::hstring const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(SampleLibraryCpp::ICustomUserControlCpp)->put_Label(*(void**)(&value)));
    }
    template <typename D> WINRT_IMPL_AUTO(Windows::UI::Xaml::DependencyProperty) consume_SampleLibraryCpp_ICustomUserControlCppStatics<D>::LabelProperty() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(SampleLibraryCpp::ICustomUserControlCppStatics)->get_LabelProperty(&value));
        return Windows::UI::Xaml::DependencyProperty{ value, take_ownership_from_abi };
    }
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, SampleLibraryCpp::ICustomUserControlCpp> : produce_base<D, SampleLibraryCpp::ICustomUserControlCpp>
    {
        int32_t __stdcall get_Label(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Label());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Label(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Label(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, SampleLibraryCpp::ICustomUserControlCppStatics> : produce_base<D, SampleLibraryCpp::ICustomUserControlCppStatics>
    {
        int32_t __stdcall get_LabelProperty(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::UI::Xaml::DependencyProperty>(this->shim().LabelProperty());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, SampleLibraryCpp::IReactPackageProvider> : produce_base<D, SampleLibraryCpp::IReactPackageProvider>
    {
    };
#endif
}
WINRT_EXPORT namespace winrt::SampleLibraryCpp
{
    inline CustomUserControlCpp::CustomUserControlCpp() :
        CustomUserControlCpp(impl::call_factory_cast<CustomUserControlCpp(*)(Windows::Foundation::IActivationFactory const&), CustomUserControlCpp>([](Windows::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CustomUserControlCpp>(); }))
    {
    }
    inline auto CustomUserControlCpp::LabelProperty()
    {
        return impl::call_factory_cast<Windows::UI::Xaml::DependencyProperty(*)(ICustomUserControlCppStatics const&), CustomUserControlCpp, ICustomUserControlCppStatics>([](ICustomUserControlCppStatics const& f) { return f.LabelProperty(); });
    }
    inline ReactPackageProvider::ReactPackageProvider() :
        ReactPackageProvider(impl::call_factory_cast<ReactPackageProvider(*)(Windows::Foundation::IActivationFactory const&), ReactPackageProvider>([](Windows::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ReactPackageProvider>(); }))
    {
    }
    inline XamlMetaDataProvider::XamlMetaDataProvider() :
        XamlMetaDataProvider(impl::call_factory_cast<XamlMetaDataProvider(*)(Windows::Foundation::IActivationFactory const&), XamlMetaDataProvider>([](Windows::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<XamlMetaDataProvider>(); }))
    {
    }
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::SampleLibraryCpp::ICustomUserControlCpp> : winrt::impl::hash_base {};
    template<> struct hash<winrt::SampleLibraryCpp::ICustomUserControlCppStatics> : winrt::impl::hash_base {};
    template<> struct hash<winrt::SampleLibraryCpp::IReactPackageProvider> : winrt::impl::hash_base {};
    template<> struct hash<winrt::SampleLibraryCpp::CustomUserControlCpp> : winrt::impl::hash_base {};
    template<> struct hash<winrt::SampleLibraryCpp::ReactPackageProvider> : winrt::impl::hash_base {};
    template<> struct hash<winrt::SampleLibraryCpp::XamlMetaDataProvider> : winrt::impl::hash_base {};
#endif
}
#endif