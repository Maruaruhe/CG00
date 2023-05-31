#include "mainRoop.h"

void MainRoop::Initialize(WindowsAPI* winAPI, DirectX12* directX12/*, GraphicsRenderer* graphicsRenderer*//*, Triangle* drawTriangle*/) {
	//window
	winAPI->RegisterWNDCLASS();

	//DirectX12
	//directX12->MakeDXGIFactory();
	//directX12->Adapter();
	//directX12->D3D12Device();
	//directX12->MakeCommandQueue();
	//directX12->MakeCommandList();
	//directX12->MakeSwapChain(winAPI);
	//directX12->MakeDescriptorHeap();
	//directX12->MakeRTV();
	//directX12->MakeFenceEvent();

	directX12->InitializeDirectX12(winAPI);

	//
	/*graphicsRenderer->InitializeDXC();
	graphicsRenderer->MakeRootSignature(directX12);
	graphicsRenderer->SetInputLayout();
	graphicsRenderer->SetBlendState();
	graphicsRenderer->SetRasterizerState();
	graphicsRenderer->ShaderCompile();
	graphicsRenderer->MakePSO(directX12);*/
	//
	//graphicsRenderer->MakeVertexResource(directX12);
	//graphicsRenderer->MakeVertexBufferView();
	//graphicsRenderer->DateResource();
	//graphicsRenderer->ViewportScissor();
	/*drawTriangle->MakeVertexResource(directX12);
	drawTriangle->MakeVertexBufferView();
	drawTriangle->DateResource();
	drawTriangle->ViewportScissor();*/
}

void MainRoop::Update(DirectX12* directX12) {
	/*directX12->DecideCommand();
	graphicsRenderer->DecideCommand(directX12);*/
	directX12->GetCommandList()->Close();
	directX12->TransitionBarrier();
	directX12->ChangeBarrier();
	directX12->KickCommand();
	directX12->SendSignal();
	directX12->WaitGPU();
}

void MainRoop::End(WindowsAPI* winAPI, DirectX12* directX12/*, GraphicsRenderer* graphicsRenderer*//*, DrawTriangle* drawTriangle*/) {
	//Release
	//directX12->AllRelease();
	////drawTriangle->AllReleasse();
	//graphicsRenderer->AllRelease();

	CloseWindow(winAPI->GetHwnd());

	directX12->ReportLiveObject();
}