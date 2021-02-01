#pragma once
#include "NativeModules.h"
#include <winrt/Windows.ApplicationModel.Background.h>

#include "winrt/Microsoft.ReactNative.h"

using namespace winrt;
using namespace Windows::ApplicationModel::Background;

namespace NAMESPACE {
	
	REACT_MODULE(MODULE);
	struct MODULE {
		REACT_METHOD(DeviceModel, L"deviceModel");
		winrt::hstring DeviceModel() noexcept;

		REACT_METHOD(RegisterNativeJsTaskHook, L"registerNativeJsTaskHook");
		void RegisterNativeJsTaskHook(std::string const& str_taskName) noexcept;
		IAsyncAction registerNativeJsTaskHook(std::string const& str_taskName) noexcept;

		REACT_INIT(Initialize);
		void Initialize(winrt::Microsoft::ReactNative::ReactContext const& reactContext) noexcept; 

		REACT_METHOD(TestFireBackgroundTask, L"testFireBackgroundTask");
		void TestFireBackgroundTask() noexcept;

		winrt::IAsyncAction MODULE::TestFireBackgroundTaskAsync() noexcept;
		ApplicationTrigger _AppTrigger;

	private:
		winrt::Microsoft::ReactNative::ReactContext m_reactContext{ nullptr };

	};

} // namespace MODULE
