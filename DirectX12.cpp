#include "DirectX12.h"
DirectX12::DirectX12() {
	
}

void DirectX12::Init() {
	IDXGIFactory7* dxgiFactory = nullptr;
	hr = CreateDXGIFactory(IID_PPV_ARGS(&dxgiFactory));
	assert(SUCCEEDED(hr));
}
void DirectX12::Adapter() {
	IDXGIAdapter4* useAdapter = nullptr;
}
void DirectX12::D3D12Device() {

}