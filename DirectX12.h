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
	DirectX12();
	~DirectX12();

	void Init(WindowsAPI* winAPI);
	void MakeDXGIFactory();
	void Adapter();
	void D3D12Device();

	void LogText(const std::string& message);
	void MakeCommandQueue();
	void MakeCommandList();
	void MakeSwapChain(WindowsAPI* winAPI);
	void MakeDescriptorHeap();
	void MakeRTV();
	void DecideCommand();
	void KickCommand();

private:
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

