#include "mainRoop.h"
#include "Vector4.h"
#include "Triangle.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//インスタンス
	MainRoop* mainRoop = new MainRoop;
	//いろいろ

	Vector2 LeftBottom1 = { -1.0f,-0.5f };
	Vector2 MiddleTop1 = { -0.5f,0.5f };
	Vector2 RightBottom1 = { -0.25f,-0.5f };

	Vector2 LeftBottom2 = { 0.f,-0.5f };
	Vector2 MiddleTop2 = { 0.5f,0.5f };
	Vector2 RightBottom2 = { 0.75f,-0.5f };

	//Vector2 LeftBottom = { 0.0f,720.0f };hh
	//Vector2 MiddleTop = { 700.0f,500.0f };
	//Vector2 RightBottom = { 1200.0f,600.0f };

	mainRoop->Initialize(mainRoop->windowsAPI, mainRoop->directX12, mainRoop->graphicsRenderer,mainRoop->triangle1);
	mainRoop->triangle1->Draw(&LeftBottom1,&MiddleTop1,&RightBottom1,mainRoop->directX12, mainRoop->graphicsRenderer);
	mainRoop->triangle2->Draw(&LeftBottom2,&MiddleTop2,&RightBottom2,mainRoop->directX12, mainRoop->graphicsRenderer);
	//mainRoop->triangle->Draw(mainRoop->directX12);
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

	mainRoop->directX12->AllRelease();
	/*mainRoop->triangle->AllReleasse();*/
	/*mainRoop->t1->AllReleasse();*/
	mainRoop->graphicsRenderer->AllRelease();
	mainRoop->End(mainRoop->windowsAPI, mainRoop->directX12, mainRoop->graphicsRenderer);
	return 0;
}