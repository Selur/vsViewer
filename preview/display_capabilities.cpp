#include "display_capabilities.h"

#include <QWindow>

#ifdef Q_OS_WIN
#include <dxgi1_6.h>
#include <windows.h>
#include <wrl/client.h>

using Microsoft::WRL::ComPtr;
#endif

//==============================================================================

DisplayCapabilities displayCapabilities(QWindow* a_pWindow)
{
  DisplayCapabilities capabilities;
#ifdef Q_OS_WIN
  if (!a_pWindow || !a_pWindow->handle()) return capabilities;
  HMONITOR monitor = MonitorFromWindow(reinterpret_cast<HWND>(a_pWindow->winId()), MONITOR_DEFAULTTONEAREST);

  ComPtr<IDXGIFactory1> factory;
  if (FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&factory)))) return capabilities;

  ComPtr<IDXGIAdapter1> adapter;
  for (UINT adapterIndex = 0; factory->EnumAdapters1(adapterIndex, &adapter) != DXGI_ERROR_NOT_FOUND; ++adapterIndex) {
    ComPtr<IDXGIOutput> output;
    for (UINT outputIndex = 0; adapter->EnumOutputs(outputIndex, &output) != DXGI_ERROR_NOT_FOUND; ++outputIndex) {
      ComPtr<IDXGIOutput6> output6;
      DXGI_OUTPUT_DESC1 description;
      if (FAILED(output.As(&output6)) || FAILED(output6->GetDesc1(&description))) continue;
      if (description.Monitor != monitor) continue;
      capabilities.known = true;
      capabilities.hdrActive = (description.ColorSpace == DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020);
      capabilities.bitsPerColor = int(description.BitsPerColor);
      return capabilities;
    }
  }
#else
  Q_UNUSED(a_pWindow);
#endif
  return capabilities;
}

// END OF DisplayCapabilities displayCapabilities(QWindow * a_pWindow)
//==============================================================================
