#include "TestScene.h"
#include "../Manager/ModelManager/ModelManager.h"
#include "../Manager/TextureManager/TextureManager.h"

void TestScene::Initialize() {
	input = Input::GetInstance();
	TextureManager::GetInstance()->LoadTexture("Resources/monsterBall.png");

	ModelManager::GetInstance()->LoadModel("axis");
	ModelManager::GetInstance()->LoadModel("plane");

	model.Initialize("plane");
	sprite.Initialize({ 0,0 }, { 320,180 }, "Resources/uvChecker.png");
}

void TestScene::Update() {
	model.Update();
	sprite.Update();
}

void TestScene::Draw() {
	model.Draw();
	sprite.Draw();
}