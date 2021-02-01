// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include "pch.h"
#include "ReactPackageProvider.g.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::NAMESPACE::implementation {

	struct ReactPackageProvider : ReactPackageProviderT<ReactPackageProvider> {
		ReactPackageProvider() = default;

		void CreatePackage(IReactPackageBuilder const& packageBuilder) noexcept;
	};

} // namespace winrt::<Namespace>::implementation

namespace winrt::NAMESPACE::factory_implementation {

	struct ReactPackageProvider : ReactPackageProviderT<ReactPackageProvider, implementation::ReactPackageProvider> {};

} // namespace winrt::<Namespace>::factory_implementation
