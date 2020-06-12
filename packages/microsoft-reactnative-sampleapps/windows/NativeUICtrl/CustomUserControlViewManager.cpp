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
        return L"BgLabelControl";
    }

    FrameworkElement CustomUserControlViewManager::CreateView() noexcept {
        auto const& view = winrt::RuntimeComponent1::BgLabelControl();

        view.RegisterPropertyChangedCallback(
            winrt::RuntimeComponent1::BgLabelControl::LabelProperty(),
            [this](
                winrt::Windows::UI::Xaml::DependencyObject obj, winrt::Windows::UI::Xaml::DependencyProperty prop) noexcept {
            if (auto c = obj.try_as<winrt::RuntimeComponent1::BgLabelControl>()) {
                ReactContext().DispatchEvent(
                    c,
                    L"topLabelChanged",
                    [this, c](winrt::Microsoft::ReactNative::IJSValueWriter const& eventDataWriter) noexcept {
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
        FrameworkElement const& view,
        IJSValueReader const& propertyMapReader) noexcept {
        if (auto control = view.try_as<winrt::RuntimeComponent1::BgLabelControl>()) {
            JSValueObject propertyMap = JSValueObject::ReadFrom(propertyMapReader);

            for (auto const& pair : propertyMap) {
                auto const& propertyName = pair.first;
                auto const& propertyValue = pair.second;

                if (propertyName == "label") {
                    if (!propertyValue.IsNull()) {
                        auto value = winrt::box_value(winrt::to_hstring(propertyValue.AsString()));
                        control.SetValue(winrt::RuntimeComponent1::BgLabelControl::LabelProperty(), value);
                    }
                    else {
                        control.ClearValue(winrt::RuntimeComponent1::BgLabelControl::LabelProperty());
                    }
                }
                else if (propertyName == "color") {
                  if (auto value = propertyValue.To<Brush>()) {
                    control.SetValue(Control::ForegroundProperty(), value);
                  }
                    else {
                        control.ClearValue(Control::ForegroundProperty());
                    }
                }
                else if (propertyName == "backgroundColor") {
                  if (auto value = propertyValue.To<Brush>()) {
                    control.SetValue(Control::BackgroundProperty(), value);
                  }
                    else {
                        control.ClearValue(Control::BackgroundProperty());
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
        FrameworkElement const& view,
        winrt::hstring commandId,
        winrt::Microsoft::ReactNative::IJSValueReader const& commandArgsReader) noexcept {
        if (auto control = view.try_as<winrt::RuntimeComponent1::BgLabelControl>()) {
            if (commandId == L"0") {
                const JSValueArray& commandArgs = JSValue::ReadArrayFrom(commandArgsReader);
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
        constantWriter.WritePropertyName(L"topLabelChanged");
        constantWriter.WriteObjectBegin();
        WriteProperty(constantWriter, L"registrationName", L"onLabelChanged");
        constantWriter.WriteObjectEnd();
      };
    }


}
