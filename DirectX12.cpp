#include "DirectX12.h"

DirectX12::DirectX12() {

}

DirectX12::~DirectX12() {

}


void DirectX12::Init(WindowsAPI* winAPI) {
	winAPI_ = winAPI;
	InitializeDXGIFactory();
	InitializeAdapter();
	InitializeDevice();
	//MakeCommandQueue();
	InitializeCommand();
	InitializeSwapChain();
	InitializeDescriptorHeap();
	InitializeRenderTargetView();
}

void DirectX12::InitializeDXGIFactory() {
	//DXGIファクトリーの生成
	dxgiFactory = nullptr;
	hr = CreateDXGIFactory(IID_PPV_ARGS(&dxgiFactory));
	assert(SUCCEEDED(hr));
}
void DirectX12::InitializeAdapter() {
	useAdapter = nullptr;

	for (UINT i = 0; dxgiFactory->EnumAdapterByGpuPreference(i, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&useAdapter)) != DXGI_ERROR_NOT_FOUND; ++i) {
		//GetAdapterInfo
		adapterDesc = {};
		hr = useAdapter->GetDesc3(&adapterDesc);
		assert(SUCCEEDED(hr));
		//ソフトウェアでなければok
		if (!(adapterDesc.Flags & DXGI_ADAPTER_FLAG3_SOFTWARE)) {
			//logに出力
			LogText(ConvertString(std::format(L"Use Adapter:{}\n", adapterDesc.Description)));
			break;
		}
		useAdapter = nullptr;
	}
	assert(useAdapter != nullptr);
}
void DirectX12::InitializeDevice() {
	device = nullptr;
	//対応レベルの配列
	D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_12_2,D3D_FEATURE_LEVEL_12_1,D3D_FEATURE_LEVEL_12_0 };
	const char* featureLevelStrings[] = { "12.2","12.1","12.0" };
	for (size_t i = 0; i < _countof(featureLevels); ++i) {
		hr = D3D12CreateDevice(useAdapter, featureLevels[i], IID_PPV_ARGS(&device));
		if (SUCCEEDED(hr)) {
			LogText(std::format("FeatureLevel:{}\n", featureLevelStrings[i]));
			break;
		}
	}
}

void DirectX12::InitializeCommand() {
	//コマンドアロケータ生成
	commandAlocator = nullptr;
	hr = device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&commandAlocator));
	assert(SUCCEEDED(hr));
	//コマンドリスト生成
	commandList = nullptr;
	hr = device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, commandAlocator, nullptr, IID_PPV_ARGS(&commandList));
	assert(SUCCEEDED(hr));
	//コマンドキュー生成
	commandQueue = nullptr;
	hr = device->CreateCommandQueue(&commandQueueDesc, IID_PPV_ARGS(&commandQueue));
	assert(SUCCEEDED(hr));
}

void DirectX12::InitializeSwapChain() {
	//スワップチェーン生成の設定
	swapChain = nullptr;
	swapChainDesc = {};

	swapChainDesc.Width = kClientWidth;
	swapChainDesc.Height = kClientHeight;
	swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 2;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;

	hr = dxgiFactory->CreateSwapChainForHwnd(commandQueue, winAPI_->GetHwnd(), &swapChainDesc, nullptr, nullptr, reinterpret_cast<IDXGISwapChain1**>(&swapChain));
	assert(SUCCEEDED(hr));
}

void DirectX12::InitializeDescriptorHeap() {
	rtvDescriptorHeap = nullptr;
	rtvDescriptorHeapDesc = {};
	rtvDescriptorHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
	rtvDescriptorHeapDesc.NumDescriptors = 2;
	hr = device->CreateDescriptorHeap(&rtvDescriptorHeapDesc, IID_PPV_ARGS(&rtvDescriptorHeap));
	assert(SUCCEEDED(hr));

	swapChainResources[0] = { nullptr };
	swapChainResources[1] = { nullptr };
	hr = swapChain->GetBuffer(0, IID_PPV_ARGS(&swapChainResources[0]));
	assert(SUCCEEDED(hr));
	hr = swapChain->GetBuffer(1, IID_PPV_ARGS(&swapChainResources[1]));
	assert(SUCCEEDED(hr));
}

void DirectX12::InitializeRenderTargetView() {
	rtvDesc = {};
	rtvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
	rtvDesc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;

	rtvStartHandle = rtvDescriptorHeap->GetCPUDescriptorHandleForHeapStart();
	rtvHandles[0] = rtvStartHandle;
	device->CreateRenderTargetView(swapChainResources[0], &rtvDesc, rtvHandles[0]);
	rtvHandles[1].ptr = rtvHandles[0].ptr + device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

	device->CreateRenderTargetView(swapChainResources[1], &rtvDesc, rtvHandles[1]);
}

void DirectX12::DecideCommand() {
	backBufferIndex = swapChain->GetCurrentBackBufferIndex();
	commandList->OMSetRenderTargets(1, &rtvHandles[backBufferIndex], false, nullptr);

	float clearColor[] = { 0.1f,0.25f,0.5f,1.0f };
	commandList->ClearRenderTargetView(rtvHandles[backBufferIndex], clearColor, 0, nullptr);
	hr = commandList->Close();
	assert(SUCCEEDED(hr));
}
void DirectX12::KickCommand() {
	ID3D12CommandList* commandLists[] = { commandList };
	commandQueue->ExecuteCommandLists(1, commandLists);

	swapChain->Present(1, 0);
	hr = commandAlocator->Reset();
	assert(SUCCEEDED(hr));
	hr = commandList->Reset(commandAlocator, nullptr);
	assert(SUCCEEDED(hr));
}