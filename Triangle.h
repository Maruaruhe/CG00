#pragma once
#include "DirectX12.h"
#include "Vector4.h"
#include "GraphicsRenderer.h"

class Triangle
{
public:
	void Draw();

	void Initialize(DirectX12* directX12, Vector4 leftBot, Vector4 midTop, Vector4 rightBot);
	void MakeVertexResource();
	void MakeMaterialResource();
	void MakeVertexBufferView();
	void DateResource();
	void MakeResource();
	void AllReleasse();

private:
	DirectX12* directX12_;

	HRESULT hr;
	//MakeVertexResource
	D3D12_HEAP_PROPERTIES uploadHeapProperties{};
	D3D12_RESOURCE_DESC vertexResourceDesc{};
	ID3D12Resource* vertexResource;
	ID3D12Resource* materialResource;
	//MakeVertexBufferView
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};
	//DateResource
	Vector4* vertexDate;
	Vector4* materialDate;
	//ViewportScissor
	D3D12_VIEWPORT viewport{};
	D3D12_RECT scissorRect{};

	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;
};

