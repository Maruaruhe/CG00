//#include "GameScene.h"
//void GameScene::Initialize(WindowsAPI* winAPI, DirectX12* directX12, Triangle* triangle) {
//	directX12->MakeDXGIFactory();
//	directX12->Adapter();
//	directX12->D3D12Device();
//	directX12->MakeCommandQueue();
//	directX12->MakeCommandList();
//	directX12->MakeSwapChain(winAPI);
//	directX12->MakeDescriptorHeap();
//	directX12->MakeRTV();
//	directX12->MakeFenceEvent();
//
//	triangle->InitializeDXC();
//	triangle->MakeRootSignature();
//	triangle->SetInputLayout();
//	triangle->SetBlendState();
//	triangle->SetRasterizerState();
//	triangle->ShaderCompile();
//	triangle->MakePSO();
//	triangle->MakeVertexResource();
//	triangle->MakeVertexBufferView();
//	triangle->DateResource();
//	triangle->ViewportScissor();
//}
//void GameScene::Update(WindowsAPI* winAPI, DirectX12* directX12, Triangle* triangle) {
//	directX12->DecideCommand();
//	directX12->TransitionBarrier();
//	directX12->ChangeBarrier();
//	directX12->KickCommand();
//	directX12->SendSignal();
//	directX12->WaitGPU();
//}
//void GameScene::Finish(WindowsAPI* winAPI, DirectX12* directX12, Triangle* triangle) {
//	directX12->AllRelease();
//	triangle->AllRelease();
//}