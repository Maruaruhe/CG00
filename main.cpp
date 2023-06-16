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
	Vector2 LeftBottom2 = { 0.25f,-0.25f };
	Vector2 MiddleTop2 = { 0.3f,0.3f };
	Vector2 RightBottom2 = { 0.4f,-0.1f };

	//初期化


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