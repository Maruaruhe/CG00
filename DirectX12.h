#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <string>
#include <format>

#include "WindowsAPI.h"

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

class DirectX12
{
public:
	IDXGIFactory7* dxgiFactory;
	HRESULT hr;
	IDXGIAdapter4* useAdapter;
	ID3D12Device* device;
	DXGI_ADAPTER_DESC3 adapterDesc{};
	ID3D12CommandQueue* commandQueue;
	D3D12_COMMAND_QUEUE_DESC commandQueueDesc{};
	ID3D12CommandAllocator* commandAlocator;
	ID3D12GraphicsCommandList* commandList;
	IDXGISwapChain4* swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;

	WindowsAPI* windowsAPI;

	DirectX12();
	~DirectX12();

	void Init();
	void MakeDXGIFactory();
	void Adapter();
	void D3D12Device();

	void GetWinAPI(WindowsAPI* winAPI);

	void LogText(const std::string& message);
	void MakeCommandQueue();
	void MakeCommandList();
	void MakeSwapChain();
};

