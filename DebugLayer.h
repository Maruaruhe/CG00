#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

class DebugLayer
{
public:
	void Debug();
	void Stop();
private:
	ID3D12Debug1* debugController;
	ID3D12InfoQueue* infoQueue;
};

