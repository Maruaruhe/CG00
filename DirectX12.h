#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

class DirectX12
{
public:
	IDXGIFactory7* dxgiFactory;
	HRESULT hr;
	IDXGIAdapter4* useAdapter;


	DirectX12();
	~DirectX12();

	void Init();
	void Adapter();
	void D3D12Device();
};

