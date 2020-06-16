//
// MyUserControl.xaml.h
// Declaration of the MyUserControl class
//

#pragma once
#include "pch.h"
#include "winrt/Windows.UI.Xaml.Controls.h"
#include "winrt/Windows.UI.Xaml.h"
#include "MyUserControl.g.h"

namespace winrt::RuntimeComponent1::implementation {

    struct MyUserControl : MyUserControlT<MyUserControl> {
  MyUserControl();

  winrt::hstring Label();
  void Label(winrt::hstring const &value);

  Windows::UI::Xaml::Media::Brush Background();
  void Background(Windows::UI::Xaml::Media::Brush const &value);

  static Windows::UI::Xaml::DependencyProperty LabelProperty();
  static Windows::UI::Xaml::DependencyProperty BackgroundProperty();

 private:
  static Windows::UI::Xaml::DependencyProperty m_labelProperty;
  static Windows::UI::Xaml::DependencyProperty m_backgroundProperty;

  static void IsBackgroundChanged(
      Windows::UI::Xaml::DependencyObject depo,
      Windows::UI::Xaml::DependencyPropertyChangedEventArgs args);

  //COLOR MyUserControl::hex2rgb(std::wstring hex);

 public:
  void Button_Click(
      winrt::Windows::Foundation::IInspectable const &sender,
      winrt::Windows::UI::Xaml::RoutedEventArgs const &e);
};


} // namespace winrt::RuntimeComponent1::implementation

namespace winrt::RuntimeComponent1::factory_implementation {
struct MyUserControl : MyUserControlT<MyUserControl, implementation::MyUserControl> {};
} // namespace winrt::RuntimeComponent1::factory_implementation
