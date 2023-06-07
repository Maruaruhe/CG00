#pragma once
#include "Vector4.h"
#include "GraphicsRenderer.h"
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <string>
#include <format>
#include <dxgidebug.h>
#include <dxcapi.h>

#include "Log.h"
#include "DirectX12.h"

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dxcompiler.lib")

class Triangle
{
public:
	void Draw(Vector2* leftBot, Vector2* midTop, Vector2* rightBot, DirectX12* directX12);
	void DecideViewportScissor(DirectX12* directX12);
	void DecideVertexBuffers(DirectX12* directX12);


	void MakeVertexResource(DirectX12* directX12);
	void MakeVertexBufferView();
	void DateResource(Vector2* leftBot, Vector2* midTop, Vector2* rightBot);
	void ViewportScissor();
	void AllReleasse();

private:
	HRESULT hr;
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

