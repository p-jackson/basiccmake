#include "demo_b.h"

#include <Windows.h>

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, wchar_t*, int) {
  auto message = run();
#if defined(UNICODE)
  auto title = "wide";
#else
  auto title = "narrow";
#endif
  MessageBoxA(nullptr, message.c_str(), title, MB_OK);
  return 0;
}
