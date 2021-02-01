#define NOMINMAX

// Change depending on if UI module or native module without UI.
#undef NATIVE_UI_MODULE // undef if NATIVE_MODULE
#define NATIVE_MODULE // undef if NATIVE_UI_MODULE

#if defined(NATIVE_UI_MODULE) && defined(NATIVE_MODULE)
#error Error NATIVE_UI_MODULE and NATIVE_MODULE are both defined. 
#endif

// For Native Modules and UI Native Modules
#define NAMESPACE NativeModule // Don't forget to update the .XAML and .IDL files for this namespace

#ifdef NATIVE_MODULE
// For Native Modules
#define MODULE	NativeModuleClass
#endif

#ifdef NATIVE_UI_MODULE
// For UI Native Modules
#define CONTROL CustomUserControl
#define VIEWMANAGER UserControlViewManager
#endif

#include "rn_macros.h"

#include <unknwn.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.System.Threading.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Data.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Navigation.h>
#include <winrt/Windows.UI.Xaml.h>

#include <winrt/Microsoft.ReactNative.h>

