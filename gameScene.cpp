#include "gameScene.h"

void GameScene::Initialize(WindowsAPI* winAPI, DirectX12* directX12/*, GraphicsRenderer* graphicsRenderer*//*, Triangle* drawTriangle*/) {

	directX12_ = directX12;
	directX12_->Init(winAPI);
	graphicsRenderer_->Initialize(directX12_);
	VariableInit();

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i] = new Triangle;
		triangle_[i]->Initialize(directX12_, triangleData[i].leftBot_, triangleData[i].middleTop_, triangleData[i].rightBot_);
	}

	graphicsRenderer_->ViewportScissor();
}

void GameScene::Update() {
	ImGui::ShowDemoWindow();

	ImGui::Render();
}

void GameScene::Release() {
	directX12_->Release();
	graphicsRenderer_->AllRelease();
}

void GameScene::Draw() {
	PreDraw();
	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i]->Draw();
	}
}

void GameScene::PreDraw() {
	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	directX12_->PreDraw();
	graphicsRenderer_->DecideCommand(directX12_);
}

void GameScene::Final() {
	directX12_->PostDraw();
}

void GameScene::End() {
	directX12_->ResourceLeakCheck();
}

void GameScene::VariableInit() {

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangleData[i].leftBot_ = { -0.5f,-0.5f + i * 0.1f,0.0f,1.0f };
		triangleData[i].middleTop_ = { 0.0f,0.5f + i * 0.1f,0.0f,1.0f };
		triangleData[i].rightBot_ = { 0.5f,-0.5f + i * 0.1f,0.0f,1.0f };
	}
}