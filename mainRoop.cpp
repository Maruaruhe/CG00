#include "mainRoop.h"

void MainRoop::Initialize(WindowsAPI* winAPI, DirectX12* directX12) {
	
	directX12_ = directX12;
	directX12_->InitializeDirectX12(winAPI);
	graphicsRenderer_->Initialize(directX12_);
	VariableInit();

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i] = new Triangle;
		triangle_[i]->Initialize(directX12_);
	}

	graphicsRenderer_->ViewportScissor();
}

void MainRoop::Update() {

}

void MainRoop::Release() {
	directX12_->AllRelease();
	graphicsRenderer_->AllRelease();
}

void MainRoop::Draw() {
	for (int i = 0; i < TRIANGLECOUNT; i++){
		triangle_[i]->Draw();
	}
}

void MainRoop::First() {
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
		triangleData[i].leftBot_ = { -1.0f + i * 0.2f,-0.5f + i * 0.2f,0.0f,1.0f };
		triangleData[i].middleTop_ = { -0.5f + i * 0.2f,0.5f + i * 0.2f,0.0f,1.0f };
		triangleData[i].rightBot_ = { 0.0f + i * 0.2f,-0.5f + i * 0.2f,0.0f,1.0f };
	}
}