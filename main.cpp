#include "mainRoop.h"
#include "Vector4.h"
#include "Triangle.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//インスタンス
	MainRoop* mainRoop = new MainRoop;
	//いろいろ

	//三角形の座標
	//一つ目
	Vector2 LeftBottom1 = { -1.0f,-0.5f };
	Vector2 MiddleTop1 = { -0.5f,0.5f };
	Vector2 RightBottom1 = { -0.25f,-0.5f };
	//二つ目
	Vector2 LeftBottom2 = { 0.0f,-0.5f };
	Vector2 MiddleTop2 = { 0.5f,0.5f };
	Vector2 RightBottom2 = { 0.5f,-0.75f };

	//初期化
	mainRoop->Initialize(mainRoop->windowsAPI, mainRoop->directX12);
	mainRoop->graphicsRenderer->Initialize(mainRoop->directX12);

	//三角形描画
	mainRoop->triangle[0]->Draw(&LeftBottom1, &MiddleTop1, &RightBottom1, mainRoop->directX12);
	mainRoop->triangle[1]->Draw(&LeftBottom2, &MiddleTop2, &RightBottom2, mainRoop->directX12);


	//メインループ
	MSG msg{};
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			mainRoop->directX12->DecideCommand();
			mainRoop->triangle[0]->DecideViewportScissor(mainRoop->directX12);
			mainRoop->triangle[1]->DecideViewportScissor(mainRoop->directX12);
			mainRoop->graphicsRenderer->DecideCommand1(mainRoop->directX12);
			mainRoop->triangle[0]->DecideVertexBuffers(mainRoop->directX12);
			mainRoop->triangle[1]->DecideVertexBuffers(mainRoop->directX12);
			mainRoop->graphicsRenderer->DecideCommand2(mainRoop->directX12);
			
			
			mainRoop->Update(mainRoop->directX12);
		}
	}

	mainRoop->directX12->AllRelease();
	mainRoop->triangle[0]->AllReleasse();
	mainRoop->triangle[1]->AllReleasse();
	mainRoop->graphicsRenderer->AllRelease();
	mainRoop->End(mainRoop->windowsAPI, mainRoop->directX12);
	return 0;
}