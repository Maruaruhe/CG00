#include "mainRoop.h"

void MainRoop::Initialize(WindowsAPI* winAPI, DirectX12* directX12/*, GraphicsRenderer* graphicsRenderer*//*, Triangle* drawTriangle*/) {
	
	directX12_ = directX12;
	winAPI_ = winAPI;
	directX12_->InitializeDirectX12(winAPI);
	graphicsRenderer_->Initialize(directX12_);

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i] = new Triangle;
		triangle_[i]->Initialize(directX12_);
	}

	graphicsRenderer_->ViewportScissor();

}

void MainRoop::Update() {
	ImGui::ShowDemoWindow();

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i]->Update();
	}

	ImGui::Render();
}

void MainRoop::Release() {
	directX12_->AllRelease();
	graphicsRenderer_->AllRelease();
}

void MainRoop::Draw() {
	for (int i = 0; i < TRIANGLECOUNT; i++){
		triangle_[i]->Draw(triangleData[i].leftBot_, triangleData[i].middleTop_, triangleData[i].rightBot_);
	}
}

void MainRoop::First() {
	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	directX12_->PreDraw();
	graphicsRenderer_->DecideCommand(directX12_);
}

void MainRoop::Final() {
	directX12_->PostDraw();
}

void MainRoop::End() {
	directX12_->ReportLiveObject();
}

void MainRoop::VariableInit() {

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangleData[i].leftBot_ = { -0.5f + i * 0.2f,-0.5f + i * 0.2f,0.0f,1.0f };
		triangleData[i].middleTop_ = { 0.0f + i * 0.2f,0.5f + i * 0.2f,0.0f,1.0f };
		triangleData[i].rightBot_ = { 0.5f + i * 0.2f,-0.5f + i * 0.2f,0.0f,1.0f };
	}
}