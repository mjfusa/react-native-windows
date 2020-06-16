#include "pch.h"
#include <winrt/Windows.UI.Xaml.Media.h>

#include "CustomUserControlViewManager.h"
#include "JSValueReader.h"
#include "JSValueXaml.h"
#include "NativeModules.h"

#include "winrt/RuntimeComponent1.h"
//#include "DebugHelpers.h"

using namespace winrt;
using namespace Microsoft::ReactNative;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Controls;

#include "winrt\RuntimeComponent1.h"

namespace winrt::NativeUICtrl::implementation {

CustomUserControlViewManager::CustomUserControlViewManager(){};

// IViewManager
hstring CustomUserControlViewManager::Name() noexcept {
  return L"MyUserControl";
}

FrameworkElement CustomUserControlViewManager::CreateView() noexcept {
  auto const &view = winrt::RuntimeComponent1::MyUserControl();

  view.RegisterPropertyChangedCallback(
      winrt::RuntimeComponent1::MyUserControl::BackgroundProperty(),
      [this](
          winrt::Windows::UI::Xaml::DependencyObject obj, winrt::Windows::UI::Xaml::DependencyProperty prop) noexcept {
        if (auto c = obj.try_as<winrt::RuntimeComponent1::MyUserControl>()) {
          ReactContext().DispatchEvent(
              c,
              L"bgPropertyChanged",
              [this, c](winrt::Microsoft::ReactNative::IJSValueWriter const &eventDataWriter) noexcept {
                auto a = c.Background();
              eventDataWriter.WriteString(c.Label());
              });
        }
      });

  return view;
}

// IViewManagerWithReactContext
IReactContext CustomUserControlViewManager::ReactContext() noexcept {
  return m_reactContext;
}

void CustomUserControlViewManager::ReactContext(IReactContext reactContext) noexcept {
  m_reactContext = reactContext;
}

// IViewManagerWithNativeProperties
IMapView<hstring, ViewManagerPropertyType> CustomUserControlViewManager::NativeProps() noexcept {
  auto nativeProps = winrt::single_threaded_map<hstring, ViewManagerPropertyType>();

  nativeProps.Insert(L"label", ViewManagerPropertyType::String);
  nativeProps.Insert(L"color", ViewManagerPropertyType::Color);
  nativeProps.Insert(L"backgroundColor", ViewManagerPropertyType::Color);

  return nativeProps.GetView();
}

void CustomUserControlViewManager::UpdateProperties(
    FrameworkElement const &view,
    IJSValueReader const &propertyMapReader) noexcept {
  if (auto control = view.try_as<winrt::RuntimeComponent1::MyUserControl>()) {
    JSValueObject propertyMap = JSValueObject::ReadFrom(propertyMapReader);

    for (auto const &pair : propertyMap) {
      auto const &propertyName = pair.first;
      auto const &propertyValue = pair.second;

      if (propertyName == "label") {
        if (!propertyValue.IsNull()) {
          auto value = winrt::box_value(winrt::to_hstring(propertyValue.AsString()));
          control.Label(winrt::to_hstring(propertyValue.AsString()));
          //control.SetValue(winrt::RuntimeComponent1::MyUserControl::Label(), value);
        } else {
          control.ClearValue(winrt::RuntimeComponent1::MyUserControl::LabelProperty());
        }
      } else if (propertyName == "color") {
        if (auto value = propertyValue.To<Brush>()) {
          control.Foreground(value);
          // control.SetValue(Control::ForegroundProperty(), value);
        } else {
          control.ClearValue(Control::ForegroundProperty());
        }
      } else if (propertyName == "backgroundColor") {
        if (!propertyValue.IsNull()) {
        if (auto value = propertyValue.To<Brush>()) {
            control.SetValue(winrt::RuntimeComponent1::MyUserControl::BackgroundProperty(), value);
        } else {
          control.ClearValue(winrt::RuntimeComponent1::MyUserControl::BackgroundProperty());
        }
        } else {
          control.ClearValue(winrt::RuntimeComponent1::MyUserControl::BackgroundProperty());
        }
      }
    }
  }
}

// IViewManagerWithCommands
IVectorView<winrt::hstring> CustomUserControlViewManager::Commands() noexcept {
  auto commands = winrt::single_threaded_vector<hstring>();
  commands.Append(L"CustomCommand");
  return commands.GetView();
}

void CustomUserControlViewManager::DispatchCommand(
    FrameworkElement const &view,
    winrt::hstring commandId,
    winrt::Microsoft::ReactNative::IJSValueReader const &commandArgsReader) noexcept {
  if (auto control = view.try_as<winrt::RuntimeComponent1::MyUserControl>()) {
    if (commandId == L"0") {
      const JSValueArray &commandArgs = JSValue::ReadArrayFrom(commandArgsReader);
      // Execute command
    }
  }
}

// IViewManagerWithExportedEventTypeConstants
ConstantProviderDelegate CustomUserControlViewManager::ExportedCustomBubblingEventTypeConstants() noexcept {
  return nullptr;
}

ConstantProviderDelegate CustomUserControlViewManager::ExportedCustomDirectEventTypeConstants() noexcept {
  return [](winrt::Microsoft::ReactNative::IJSValueWriter const &constantWriter) {
    constantWriter.WritePropertyName(L"bgPropertyChanged");
    constantWriter.WriteObjectBegin();
    WriteProperty(constantWriter, L"registrationName", L"onBackgroundChanged");
    constantWriter.WriteObjectEnd();
  };
}

} // namespace winrt::NativeUICtrl::implementation
