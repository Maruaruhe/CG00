#include "GameScene.h"
void GameScene::Initialize() {
	winAPI->Init();
	directX->Init(winAPI);
}

void GameScene::Update() {
	PreDraw();

	PostDraw();
}

void GameScene::PreDraw() {
	directX->DecideCommand();
}

void GameScene::PostDraw() {
	directX->KickCommand();
}