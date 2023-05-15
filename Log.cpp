#include "Log.h"
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

void Log::LogText(const std::string& message) {
	OutputDebugStringA(message.c_str());
}

