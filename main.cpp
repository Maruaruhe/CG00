#include "WindowsAPI.h"
#include "DirectX12.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//インスタンス
	WindowsAPI* winAPI;
	winAPI = new WindowsAPI;
	DirectX12* directX12;
	directX12 = new DirectX12;

	//GameScene* gameScene;
	//gameScene = new GameScene();

	//いろいろ
	//gameScene->Initialize(winAPI,directX12);
	winAPI->Init();
	directX12->Init(winAPI);

	//メインループ
	MSG msg{};
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			//gameScene->Update();
			directX12->DecideCommand();

			directX12->KickCommand();
		}
	}
	return 0;
}