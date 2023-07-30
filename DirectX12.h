#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <string>
#include <format>
#include <dxgidebug.h>
#include <dxcapi.h>

#include "WindowsAPI.h"
#include "Vector4.h"

#include "ImGuiWND.h"

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dxcompiler.lib")

class DirectX12
{
public:
	DirectX12();
	~DirectX12();

	void InitializeDirectX12(WindowsAPI* winAPI);
	void Update();

	
	void MakeDXGIFactory();
	void Adapter();
	void D3D12Device();

	void MakeCommandQueue();
	void MakeCommandList();
	void CloseCommandList();
	void MakeSwapChain();
	ID3D12DescriptorHeap* CreateDescriptorHeap(ID3D12Device* device, D3D12_DESCRIPTOR_HEAP_TYPE heapType, UINT numDescriptors, bool shaderVisible);
	void MakeDescriptorHeap();
	void MakeRTV();
	void DecideCommand();
	void KickCommand();
	void Debug();
	void Stop();

	void TransitionBarrier();
	void ChangeBarrier();
	void MakeFenceEvent();
	void SendSignal();
	void WaitGPU();
	void RTV();

	void ReportLiveObject();
	void AllRelease();
	void End(WindowsAPI* winAPI);

	void SetImGuiDescriptorHeap();
	void KickImGuiCommand();

	void PreDraw();
	void PostDraw();
	ID3D12Device* GetDevice()const { return device; }
	ID3D12GraphicsCommandList* GetCommandList() { return commandList; }
	DXGI_SWAP_CHAIN_DESC1 GetSwapChainDesc() { return swapChainDesc; }
	D3D12_RENDER_TARGET_VIEW_DESC GetRtvDesc() { return rtvDesc; }
	ID3D12DescriptorHeap* GetSrvDescriptorHeap() { return srvDescriptorHeap; }

	ID3D12Resource* CreateBufferResource(ID3D12Device* device, size_t sizeInBytes);
private:
	WindowsAPI* winAPI_;
	IDXGIFactory7* dxgiFactory;
	HRESULT hr;
	IDXGIAdapter4* useAdapter;
	ID3D12Device* device;
	DXGI_ADAPTER_DESC3 adapterDesc{};

	ID3D12CommandQueue* commandQueue;
	D3D12_COMMAND_QUEUE_DESC commandQueueDesc{};
	ID3D12CommandAllocator* commandAllocator;
	ID3D12GraphicsCommandList* commandList;
	IDXGISwapChain4* swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	ID3D12DescriptorHeap* rtvDescriptorHeap;
	ID3D12DescriptorHeap* srvDescriptorHeap;
	D3D12_DESCRIPTOR_HEAP_DESC rtvDescriptorHeapDesc{};
	ID3D12Resource* swapChainResources[2];
	D3D12_RENDER_TARGET_VIEW_DESC rtvDesc{};
	D3D12_CPU_DESCRIPTOR_HANDLE rtvStartHandle;
	D3D12_CPU_DESCRIPTOR_HANDLE rtvHandles[2];
	UINT backBufferIndex;
	ID3D12Debug1* debugController;
	ID3D12InfoQueue* infoQueue;

	D3D12_RESOURCE_BARRIER barrier{};
	ID3D12Fence* fence;
	uint64_t fenceValue;
	HANDLE fenceEvent;
	
	IDXGIDebug1* debug;
	
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;
};

