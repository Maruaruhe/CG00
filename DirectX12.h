#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <format>

#include "Log.h"
#include "WindowsAPI.h"

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

class DirectX12
{
public:
	void Init(WindowsAPI* winAPI);

private:
	void InitializeDXGIFactory();
	void InitializeAdapter();
	void InitializeDevice();
	void InitializeCommand();
	void InitializeSwapChain();
	void InitializeDescriptorHeap();
	void InitializeRenderTargetView();
	void DecideCommand();
	void KickCommand();

private:
	WindowsAPI* winAPI_;

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

	ID3D12DescriptorHeap* rtvDescriptorHeap;
	D3D12_DESCRIPTOR_HEAP_DESC rtvDescriptorHeapDesc{};
	ID3D12Resource* swapChainResources[2];
	D3D12_RENDER_TARGET_VIEW_DESC rtvDesc{};
	D3D12_CPU_DESCRIPTOR_HANDLE rtvStartHandle;
	D3D12_CPU_DESCRIPTOR_HANDLE rtvHandles[2];
	UINT backBufferIndex;

	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;
};

