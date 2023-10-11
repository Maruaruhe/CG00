#include "GameScene.h"
void GameScene::Initialize() {
	winAPI_->Init();
	directX_->Init(winAPI_);
}

void GameScene::Update() {
	PreDraw();

	PostDraw();
}

void GameScene::PreDraw() {
	directX_->DecideCommand();
}

void GameScene::PostDraw() {
	directX_->KickCommand();
}