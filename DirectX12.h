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

	void LogText(const std::string& message);
	void MakeCommandQueue();
	void MakeCommandList();
	void MakeSwapChain(WindowsAPI* winAPI);
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

	void ReportLiveObject();
	void AllRelease();
	void End(WindowsAPI* winAPI);

	void InitializeDXC();

	IDxcBlob* CompileShader(
		const std::wstring& filepath,
		const wchar_t* profile,
		IDxcUtils* dxcUtiles,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler
	);

	void MakeRootSignature();
	void SetInputLayout();
	void SetBlendState();
	void SetRasterizerState();
	void ShaderCompile();
	void MakePSO();
	void MakeVertexResource();
	void MakeVertexBufferView();
	void DateResource();
	void ViewportScissor();

	ID3D12Device* GetDevice()const { return device; }

private:
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

	//InitializeDXC
	IDxcUtils* dxcUtils;
	IDxcCompiler3* dxcCompiler;
	IDxcIncludeHandler* includeHandler;
	//MakeRootSignature
	D3D12_ROOT_SIGNATURE_DESC descriptionRootSignature{};
	ID3DBlob* signatureBlob;
	ID3DBlob* errorBlob;
	ID3D12RootSignature* rootSignature;
	//SetInputLayout
	D3D12_INPUT_ELEMENT_DESC inputElementDescs[1];
	D3D12_INPUT_LAYOUT_DESC inputLayoutDesc{};
	//SetBlendState
	D3D12_BLEND_DESC blendDesc{};
	//SetRasterizerState
	D3D12_RASTERIZER_DESC rasterizerDesc{};
	//ShaderCompile
	IDxcBlob* vertexShaderBlob;
	IDxcBlob* pixelShaderBlob;
	//MakePSO
	D3D12_GRAPHICS_PIPELINE_STATE_DESC graphicsPipelineStateDesc{};
	ID3D12PipelineState* graphicsPipelineState;
	//MakeVertexResource
	D3D12_HEAP_PROPERTIES uploadHeapProperties{};
	D3D12_RESOURCE_DESC vertexResourceDesc{};
	ID3D12Resource* vertexResource;
	//MakeVertexBufferView
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};
	//DateResource
	Vector4* vertexDate;
	//ViewportScissor
	D3D12_VIEWPORT viewport{};
	D3D12_RECT scissorRect{};

	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;
};

