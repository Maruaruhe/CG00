#pragma once
#include <Windows.h>
#include <cstdint>

class WindowsAPI
{
public:
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;

	WNDCLASS wc{};
	RECT wrc{};

	WindowsAPI();
	~WindowsAPI();

	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	void Init();
	void RegisterWNDCLASS();
};

