#include "mainRoop.h"
#include "Vector4.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//インスタンス
	MainRoop* mainRoop = new MainRoop;
	//いろいろ
	mainRoop->Initialize(mainRoop->windowsAPI, mainRoop->directX12, mainRoop->triangle);



	//メインループ
	MSG msg{};
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			mainRoop->Update(mainRoop->directX12, mainRoop->triangle);
		}
	}
	mainRoop->End(mainRoop->windowsAPI, mainRoop->directX12, mainRoop->triangle);
	return 0;
}