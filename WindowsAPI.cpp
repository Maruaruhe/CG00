#include "WindowsAPI.h"
#include "ImGuiWND.h"

WindowsAPI::WindowsAPI() {
	wc = {};
	wrc = {};
}
WindowsAPI::~WindowsAPI() {
}

//Window Procedure
LRESULT WindowsAPI::WindowProc(HWND hwnd_, UINT msg, WPARAM wparam, LPARAM lparam) {
	if (ImGui_ImplWin32_WndProcHandler(hwnd_, msg, wparam, lparam)) {
		return true;
	}

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd_, msg, wparam, lparam);
}

void WindowsAPI::Init() {
	RegisterWNDCLASS();
}

void WindowsAPI::RegisterWNDCLASS() {
	wc.lpfnWndProc = WindowProc;

	wc.lpszClassName = L"CG2WindowClass";

	wc.hInstance = GetModuleHandle(nullptr);

	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	RegisterClass(&wc);

	wrc = { 0,0,kClientWidth,kClientHeight };

	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);


	//ウィンドウの生成
	hwnd_ = CreateWindow(
		wc.lpszClassName,
		L"CG",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wrc.right - wrc.left,
		wrc.bottom - wrc.top,
		nullptr,
		nullptr,
		wc.hInstance,
		nullptr
	);
	ShowWindow(hwnd_, SW_SHOW);
}