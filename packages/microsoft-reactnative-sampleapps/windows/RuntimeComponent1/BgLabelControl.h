// BgLabelControl.h
#pragma once
#include "BgLabelControl.g.h"

namespace winrt::RuntimeComponent1::implementation
{
    struct BgLabelControl : BgLabelControlT<BgLabelControl>
    {
        BgLabelControl() { DefaultStyleKey(winrt::box_value(L"RuntimeComponent1.BgLabelControl")); }

        winrt::hstring Label()
        {
            return winrt::unbox_value<winrt::hstring>(GetValue(m_labelProperty));
        }

        void Label(winrt::hstring const& value)
        {
            SetValue(m_labelProperty, winrt::box_value(value));
        }


        static Windows::UI::Xaml::DependencyProperty LabelProperty();

        static void OnLabelChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);

    private:
        static Windows::UI::Xaml::DependencyProperty m_labelProperty;
    };
}
namespace winrt::RuntimeComponent1::factory_implementation
{
struct BgLabelControl : BgLabelControlT<BgLabelControl, implementation::BgLabelControl> {};
}
