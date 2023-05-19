#include "Command.h"

Command::Command() {
}
Command::~Command() {

}

void Command::MakeCommandQueue() {
	commandQueue = nullptr;
	directX12.hr = directX12.device->CreateCommandQueue(&commandQueueDesc, IID_PPV_ARGS(&commandQueue));
	assert(SUCCEEDED(directX12.hr));
}
void Command::MakeCommandList() {
	commandAlocator = nullptr;
	directX12.hr = directX12.device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&commandAlocator));
	assert(SUCCEEDED(directX12.hr));

	commandList = nullptr;
	directX12.hr = directX12.device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, commandAlocator, nullptr, IID_PPV_ARGS(&commandList));
	assert(SUCCEEDED(directX12.hr));
}
void Command::MakeSwapChain() {
	swapChain = nullptr;
	swapChainDesc.Width = kClientWidth;
	swapChainDesc.Height = kClientHeight;
	swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 2;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;

	directX12.hr = directX12.dxgiFactory->CreateSwapChainForHwnd(commandQueue, hwnd, &swapChainDesc, nullptr, nullptr, reinterpret_cast<IDXGISwapChain1**>(&swapChain));
	assert(SUCCEEDED(directX12.hr));
}