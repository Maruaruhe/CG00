#include "WindowsAPI.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//インスタンス
	WindowsAPI windowsAPI;

	//いろいろ
	windowsAPI.RegisterWNDCLASS();

	//メインループ
	MSG msg{};
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {

		}
	}
	return 0;
}