#pragma once
#include "DirectX12.h"
#include "Vector4.h"
#include "GraphicsRenderer.h"

class Triangle
{
public:
	void Draw(Vector4 leftBot, Vector4 midTop, Vector4 rightBot);

	void Initialize(DirectX12* directX12);
	void MakeVertexResource(DirectX12* directX12);
	void MakeVertexBufferView();
	void DateResource();
	void AllReleasse();

private:
	DirectX12* directX12_;

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

