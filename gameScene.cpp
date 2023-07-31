#include "gameScene.h"



void GameManager::Init(DirectX12* directX12, WindowsAPI* windowsAPI)
{
	for (int i = 0; i < MAXTRIANGLE; i++) {
		triangle_[i] = new Triangle;
	}

	directX12_ = directX12;
	directX12_->Init(windowsAPI);

	graphicsRenderer_->Initialize(directX12);

	for (int i = 0; i < MAXTRIANGLE; i++) {
		triangle_[i]->Initialize(directX12_, triangleData[i]);
	}

	graphicsRenderer_->ViewportScissor();
}

void GameManager::Update() {
	ImGui::ShowDemoWindow();

	for (int i = 0; i < MAXTRIANGLE; i++) {
		triangle_[i]->Update();
	}

	ImGui::Render();
}

void GameManager::Release() {
	directX12_->Release();
	graphicsRenderer_->AllRelease();
	for (int i = 0; i < MAXTRIANGLE; i++) {
		triangle_[i]->Release();
	}
}



void GameManager::BeginFrame() {
	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	directX12_->PreDraw();
	graphicsRenderer_->DecideCommand(directX12_);
}

void GameManager::EndFrame() {
	directX12_->PostDraw();
}

void GameManager::Finalize() {
	directX12_->ResourceLeakCheck();
}

void GameManager::Draw() {
	for (int i = 0; i < MAXTRIANGLE; i++) {
		triangle_[i]->Draw();
	}

}

void GameManager::VariableInit() {

	for (int i = 0; i < MAXTRIANGLE; i++) {
		triangleData[i].Left_ = { -0.5f,-0.5f + i * 0.1f,0.0f,1.0f };
		triangleData[i].Top_ = { 0.0f,0.5f + i * 0.1f,0.0f,1.0f };
		triangleData[i].Right_ = { 0.5f,-0.5f + i * 0.1f,0.0f,1.0f };
	}

	for (int i = 0; i < MAXTRIANGLE; i++) {
		triangle_[i] = new Triangle;
		triangle_[i]->Initialize(directX12_, triangleData[i]);
	}
}
