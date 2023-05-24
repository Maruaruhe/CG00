#include "WindowsAPI.h"
#include "DirectX12.h"
//#include "Command.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//インスタンス
	WindowsAPI windowsAPI;
	DirectX12 directX12;

	//いろいろ
	windowsAPI.RegisterWNDCLASS();
	directX12.Init(&windowsAPI);


	//メインループ
	MSG msg{};
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			directX12.Update();
		}
	}
	directX12.End(&windowsAPI);
	return 0;
}