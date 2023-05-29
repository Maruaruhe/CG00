#include "mainRoop.h"
#include "Vector4.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//インスタンス
	MainRoop* mainRoop = new MainRoop;
	//いろいろ
	Vector2 LeftBottom = { -0.5f,-0.5f };
	Vector2 MiddleTop = { 0.0f,0.5f };
	Vector2 RightBottom = { 0.5f,-0.5f };

	//Vector2 LeftBottom = { 0.0f,720.0f };
	//Vector2 MiddleTop = { 700.0f,500.0f };
	//Vector2 RightBottom = { 1200.0f,600.0f };

	mainRoop->Initialize(mainRoop->windowsAPI, mainRoop->directX12, mainRoop->graphicsRenderer);
	//mainRoop->t1->Draw(/*&LeftBottom, &MiddleTop, &RightBottom, */mainRoop->directX12);


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

	//mainRoop->directX12->AllRelease();
	/*mainRoop->t1->AllReleasse();*/
	//mainRoop->graphicsRenderer->AllRelease();
	mainRoop->End(mainRoop->windowsAPI, mainRoop->directX12, mainRoop->graphicsRenderer);
	return 0;
}