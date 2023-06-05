#pragma once
#include "DirectX12.h"
#include "Vector4.h"
#include "GraphicsRenderer.h"

class Triangle
{
public:
	void Draw(Vector2* leftBot, Vector2* midTop, Vector2* rightBot, DirectX12* directX12,GraphicsRenderer* gra);

//	void MakeVertexResource(DirectX12* directX12);
//	void MakeVertexBufferView();
//	void DateResource(/*Vector2* v1, Vector2* v2, Vector2* v3*/);
//	void ViewportScissor();
//	void AllReleasse();
//
//private:
//	HRESULT hr;
//	//MakeVertexResource
//	D3D12_HEAP_PROPERTIES uploadHeapProperties{};
//	D3D12_RESOURCE_DESC vertexResourceDesc{};
//	ID3D12Resource* vertexResource;
//	//MakeVertexBufferView
//	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};
//	//DateResource
//	Vector4* vertexDate;
//	//ViewportScissor
//	D3D12_VIEWPORT viewport{};
//	D3D12_RECT scissorRect{};
//
//	const int32_t kClientWidth = 1280;
//	const int32_t kClientHeight = 720;
};

