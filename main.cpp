#include "mainRoop.h"
#include "Vector4.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//インスタンス
	MainRoop* mainRoop = new MainRoop;
	//いろいろ
	Vector2 LeftBottom = {};
	Vector2 MiddleTop = {};
	Vector2 RightBottom = {};

	mainRoop->Initialize(mainRoop->windowsAPI, mainRoop->directX12, mainRoop->graphicsRenderer);



	//メインループ
	MSG msg{};
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			mainRoop->Update(mainRoop->directX12, mainRoop->graphicsRenderer);
		}
	}
	mainRoop->End(mainRoop->windowsAPI, mainRoop->directX12, mainRoop->graphicsRenderer);
	return 0;
}