//
// MyUserControl.xaml.cpp
// Implementation of the MyUserControl class
//
#include "pch.h"
#include "MyUserControl.xaml.h"
#include "MyUserControl.g.cpp"


using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Controls;


// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236
namespace winrt::RuntimeComponent1::implementation {

MyUserControl::MyUserControl() {
  InitializeComponent();
}

Windows::UI::Xaml::DependencyProperty MyUserControl::m_labelProperty = Windows::UI::Xaml::DependencyProperty::Register(
    L"Label",
    winrt::xaml_typename<winrt::hstring>(),
    winrt::xaml_typename<RuntimeComponent1::MyUserControl>(),
    Windows::UI::Xaml::PropertyMetadata{winrt::box_value(L"default label")});

Windows::UI::Xaml::DependencyProperty MyUserControl::LabelProperty() {
  return m_labelProperty;
}

winrt::hstring MyUserControl::Label() {
    auto str = winrt::unbox_value<winrt::hstring>(GetValue(m_labelProperty));
    return winrt::unbox_value<winrt::hstring>(GetValue(m_labelProperty));
}

void MyUserControl::Label(winrt::hstring const &value) {
  SetValue(m_labelProperty, winrt::box_value(value));
  txtBlock().Text(value);
}

Windows::UI::Xaml::DependencyProperty MyUserControl::m_backgroundProperty =
    Windows::UI::Xaml::DependencyProperty::Register(
        L"Background",
        winrt::xaml_typename<Windows::UI::Xaml::Media::Brush>(),
        winrt::xaml_typename<RuntimeComponent1::MyUserControl>(),
        Windows::UI::Xaml::PropertyMetadata{
            winrt::box_value(SolidColorBrush(Colors::White())),
            PropertyChangedCallback(&MyUserControl::IsBackgroundChanged)});

void MyUserControl::IsBackgroundChanged(DependencyObject depo, DependencyPropertyChangedEventArgs args) {
  auto o = depo.try_as<MyUserControl>();
  auto b = args.NewValue().try_as<Brush>();
  auto sp = o->spMain();
  sp.Background(b);
}


Windows::UI::Xaml::DependencyProperty MyUserControl::BackgroundProperty() {
  return m_backgroundProperty;
}

Windows::UI::Xaml::Media::Brush MyUserControl::Background() {
  auto brush = GetValue(m_backgroundProperty).as<Brush>();
  return brush;
}

void MyUserControl::Background(Windows::UI::Xaml::Media::Brush const &value) {
  SetValue(m_backgroundProperty, winrt::box_value(value));
  spMain().Background(value);
}

void MyUserControl::Button_Click(
    winrt::Windows::Foundation::IInspectable const &sender,
    winrt::Windows::UI::Xaml::RoutedEventArgs const &e) {

    Label(winrt::to_hstring(L"Clicked!"));
  Background(Background());
}

} // namespace winrt::RuntimeComponent1::implementation
