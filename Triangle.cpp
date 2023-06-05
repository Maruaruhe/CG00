#include "Triangle.h"

void Triangle::Draw(Vector2* leftBot, Vector2* midTop, Vector2* rightBot, DirectX12* directX12){
	MakeVertexResource(directX12);
	MakeVertexBufferView();
	DateResource(leftBot, midTop, rightBot);
	ViewportScissor();
}

void Triangle::MakeVertexResource(DirectX12* directX12) {
	//VertexResourceを生成する--------------------------------------------------------------------------------
	//頂点リソース用のヒープの作成の設定
	uploadHeapProperties = {};
	uploadHeapProperties.Type = D3D12_HEAP_TYPE_UPLOAD;
	//頂点リソースの設定
	vertexResourceDesc = {};
	//バッファリソース。テクスチャの場合はまた別の設定をする
	vertexResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	vertexResourceDesc.Width = sizeof(Vector4) * 3;
	//バッファの場合はこれらは１にする決まり
	vertexResourceDesc.Height = 1;
	vertexResourceDesc.DepthOrArraySize = 1;
	vertexResourceDesc.MipLevels = 1;
	vertexResourceDesc.SampleDesc.Count = 1;
	//バッファの場合はこれにする決まり
	vertexResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
	//実際に頂点リソースを作る
	vertexResource = nullptr;
	hr = directX12->GetDevice()->CreateCommittedResource(&uploadHeapProperties, D3D12_HEAP_FLAG_NONE, &vertexResourceDesc, D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(&vertexResource));
	assert(SUCCEEDED(hr));
}
void Triangle::MakeVertexBufferView() {
	vertexBufferView = {};
	vertexBufferView.BufferLocation = vertexResource->GetGPUVirtualAddress();
	vertexBufferView.SizeInBytes = sizeof(Vector4) * 3;
	vertexBufferView.StrideInBytes = sizeof(Vector4);
}
void Triangle::DateResource(Vector2* leftBot, Vector2* midTop, Vector2* rightBot) {
	vertexDate = nullptr;
	vertexResource->Map(0, nullptr, reinterpret_cast<void**>(&vertexDate));
	//LeftBottom
	vertexDate[0] = { leftBot->x,leftBot->y	,0.0f,1.0f };
	//MiddleTop
	vertexDate[1] = { midTop->x,midTop->y,0.0f,1.0f };
	//RightBottom
	vertexDate[2] = { rightBot->x,rightBot->y,0.0f,1.0f };
}
void Triangle::ViewportScissor() {
	viewport = {};
	viewport.Width = float(kClientWidth);
	viewport.Height = float(kClientHeight);
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	scissorRect = {};
	scissorRect.left = 0;
	scissorRect.right = kClientWidth;
	scissorRect.top = 0;
	scissorRect.bottom = kClientHeight;
}
void Triangle::AllReleasse() {
	vertexResource->Release();
}

void Triangle::DecideViewportScissor(DirectX12* directX12) {
	directX12->GetCommandList()->RSSetViewports(1, &viewport);
	directX12->GetCommandList()->RSSetScissorRects(1, &scissorRect);
}
void Triangle::DecideVertexBuffers(DirectX12* directX12) {
	directX12->GetCommandList()->IASetVertexBuffers(0, 1, &vertexBufferView);
}