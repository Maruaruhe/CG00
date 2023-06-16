#include "mainRoop.h"

void MainRoop::Initialize(WindowsAPI* winAPI, DirectX12* directX12/*, GraphicsRenderer* graphicsRenderer*//*, Triangle* drawTriangle*/) {
	
	directX12_ = directX12;
	directX12_->InitializeDirectX12(winAPI);

	graphicsRenderer_->InitializeDXC();
	graphicsRenderer_->MakeRootSignature(directX12_);
	graphicsRenderer_->SetInputLayout();
	graphicsRenderer_->SetBlendState();
	graphicsRenderer_->SetRasterizerState();
	graphicsRenderer_->ShaderCompile();
	graphicsRenderer_->MakePSO(directX12_);

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
		triangle_[i]->Draw(triangleData[i].leftBot_, triangleData[i].middleTop_, triangleData[i].rightBot_);
	}
}