#include "Log.h"
#include <d3d12.h>

#pragma comment(lib,"d3d12.lib")

void Log::LogText(const std::string& message) {
	OutputDebugStringA(message.c_str());
}