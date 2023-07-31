#include "gameScene.h"



void GameScene::Initialize(DirectX12* directX12, WindowsAPI* windowsAPI)
{
	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i] = new Triangle;
	}

	directX12_ = directX12;
	directX12_->Init(windowsAPI);
	colorVolume[0] = 0;
	colorVolume[1] = 0;
	colorVolume[2] = 0;

	graphicsRenderer_->Initialize(directX12);

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i]->Initialize(directX12_, triangleData[i]);
	}

	graphicsRenderer_->ViewportScissor();
}

void GameScene::Update() {
	ImGui::ShowDemoWindow();

	ImGui::ColorEdit3("TriangleColor", colorVolume);
	ImGui::SliderFloat3("TriangleColor", colorVolume, 0.0f, 1.0f);

	Vector4 color = {colorVolume[0],colorVolume[1],colorVolume[2],1.0f};

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i]->Update(color);
	}

	ImGui::Render();
}

void GameScene::Release() {
	directX12_->Release();
	graphicsRenderer_->Release();
	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i]->Release();
	}
}



void GameScene::BeginFrame() {
	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	directX12_->PreDraw();
	graphicsRenderer_->DecideCommand(directX12_);
}

void GameScene::EndFrame() {
	directX12_->PostDraw();
}

void GameScene::Final() {
	directX12_->ResourceLeakCheck();
}

void GameScene::Draw() {
	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i]->Draw();
	}

}

void GameScene::VariableInit() {

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangleData[i].Left_ = { -0.5f+i*0.1f,-0.5f + i * 0.1f,0.0f,1.0f };
		triangleData[i].Top_ = { 0.0f + i * 0.1f,0.5f + i * 0.1f,0.0f,1.0f };
		triangleData[i].Right_ = { 0.5f + i * 0.1f,-0.5f + i * 0.1f,0.0f,1.0f };
	}

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i] = new Triangle;
		triangle_[i]->Initialize(directX12_, triangleData[i]);
	}
}
