#include "mainRoop.h"

void MainRoop::Initialize(WindowsAPI* winAPI, DirectX12* directX12, Triangle* triangle) {
	//window
	winAPI->RegisterWNDCLASS();

	//DirectX12
	directX12->MakeDXGIFactory();
	directX12->Adapter();
	directX12->D3D12Device();
	directX12->MakeCommandQueue();
	directX12->MakeCommandList();
	directX12->MakeSwapChain(winAPI);
	directX12->MakeDescriptorHeap();
	directX12->MakeRTV();
	directX12->MakeFenceEvent();

	//
	triangle->InitializeDXC();
	triangle->MakeRootSignature(directX12);
	triangle->SetInputLayout();
	triangle->SetBlendState();
	triangle->SetRasterizerState();
	triangle->ShaderCompile();
	triangle->MakePSO(directX12);
	triangle->MakeVertexResource(directX12);
	triangle->MakeVertexBufferView();
	triangle->DateResource();
	triangle->ViewportScissor();
}

void MainRoop::Update(DirectX12* directX12,Triangle* triangle) {
	directX12->DecideCommand();
	triangle->DecideCommand(directX12);
	directX12->TransitionBarrier();
	directX12->ChangeBarrier();
	directX12->KickCommand();
	directX12->SendSignal();
	directX12->WaitGPU();
}

void MainRoop::End(WindowsAPI* winAPI, DirectX12* directX12, Triangle* triangle) {
	//Release
	directX12->AllRelease();
	triangle->AllRelease();

	CloseWindow(winAPI->GetHwnd());

	directX12->ReportLiveObject();
}