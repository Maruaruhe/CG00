#pragma once
#include "DirectX12.h"

class Command
{
public:
	ID3D12CommandQueue* commandQueue;
	D3D12_COMMAND_QUEUE_DESC commandQueueDesc{};
	ID3D12CommandAllocator* commandAlocator;
	ID3D12GraphicsCommandList* commandList;
	IDXGISwapChain4* swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;

	HWND hwnd;

	DirectX12 directX12;

	Command();
	~Command();

	void MakeCommandQueue();
	void MakeCommandList();
	void MakeSwapChain();
};

