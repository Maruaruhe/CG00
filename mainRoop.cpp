#include "mainRoop.h"

void MainRoop::Initialize(WindowsAPI* winAPI, DirectX12* directX12, GraphicsRenderer* graphicsRenderer/*, DrawTriangle* drawTriangle*/) {
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
	graphicsRenderer->InitializeDXC();
	graphicsRenderer->MakeRootSignature(directX12);
	graphicsRenderer->SetInputLayout();
	graphicsRenderer->SetBlendState();
	graphicsRenderer->SetRasterizerState();
	graphicsRenderer->ShaderCompile();
	graphicsRenderer->MakePSO(directX12);
	//
	//graphicsRenderer->MakeVertexResource(directX12);
	//graphicsRenderer->MakeVertexBufferView();
	//graphicsRenderer->DateResource();
	//graphicsRenderer->ViewportScissor();
}

void MainRoop::Update(DirectX12* directX12,GraphicsRenderer* graphicsRenderer) {
	directX12->DecideCommand();
	graphicsRenderer->DecideCommand(directX12);
	directX12->TransitionBarrier();
	directX12->ChangeBarrier();
	directX12->KickCommand();
	directX12->SendSignal();
	directX12->WaitGPU();
}

void MainRoop::End(WindowsAPI* winAPI, DirectX12* directX12, GraphicsRenderer* graphicsRenderer/*, DrawTriangle* drawTriangle*/) {
	//Release
	//directX12->AllRelease();
	////drawTriangle->AllReleasse();
	//graphicsRenderer->AllRelease();

	CloseWindow(winAPI->GetHwnd());

	directX12->ReportLiveObject();
}