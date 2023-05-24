#include "WindowsAPI.h"
#include "DirectX12.h"
#include "Triangle.h"
#include "Vector4.h"
//#include "Command.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//インスタンス
	WindowsAPI* windowsAPI = new WindowsAPI;
	DirectX12* directX12 = new DirectX12;
	Triangle* triangle = new Triangle;

	//いろいろ
	windowsAPI->RegisterWNDCLASS();
	directX12->InitializeDirectX12(windowsAPI);
	triangle->SetPos(Vector4{});



	//メインループ
	MSG msg{};
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			directX12->Update();
		}
	}
	directX12->End(windowsAPI);
	return 0;
}