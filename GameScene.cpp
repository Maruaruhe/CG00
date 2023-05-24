#include "GameScene.h"
void GameScene::Initialize(WindowsAPI* winAPI, DirectX12* directX12, Triangle* triangle) {
	winAPI->RegisterWNDCLASS();
	directX12->InitializeDirectX12(winAPI);

	triangle->InitializeDXC();
	triangle->MakeRootSignature();
	triangle->SetInputLayout();
	triangle->SetBlendState();
	triangle->SetRasterizerState();
	triangle->ShaderCompile();
	triangle->MakePSO();
	triangle->MakeVertexResource();
	triangle->MakeVertexBufferView();
	triangle->DateResource();
	triangle->ViewportScissor();
}
void GameScene::Update(DirectX12* directX12, Triangle* triangle) {
	directX12->DecideCommand();
	directX12->Update();
}
void GameScene::Finish(DirectX12* directX12, Triangle* triangle) {
	directX12->AllRelease();
	triangle->AllRelease();
}

void GameScene::DecideCommand(DirectX12* directX12, Triangle* triangle) {
	directX12.
}