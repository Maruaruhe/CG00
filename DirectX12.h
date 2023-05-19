#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <string>
#include <format>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

class DirectX12
{
public:
	IDXGIFactory7* dxgiFactory;
	HRESULT hr;
	IDXGIAdapter4* useAdapter;
	ID3D12Device* device;


	DirectX12();
	~DirectX12();

	void Init();
	void MakeDXGIFactory();
	void Adapter();
	void D3D12Device();
	void LogText(const std::string& message);
};

