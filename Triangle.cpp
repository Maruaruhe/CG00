#include "Triangle.h"

void Triangle::Initialize(DirectX12* directX12, Vector4 leftBot, Vector4 midTop, Vector4 rightBot) {
	directX12_ = directX12;
	MakeVertexResource(directX12);
	MakeVertexBufferView();
	DateResource();
	//左下
	vertexDate[0] = leftBot;
	//上
	vertexDate[1] = midTop;
	//右下
	vertexDate[2] = rightBot;
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
void Triangle::DateResource() {
	vertexResource->Map(0, nullptr, reinterpret_cast<void**>(&vertexDate));
}
void Triangle::AllReleasse() {
	vertexResource->Release();
}

void Triangle::Draw() {
	directX12_->GetCommandList()->IASetVertexBuffers(0, 1, &vertexBufferView);
	directX12_->GetCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	directX12_->GetCommandList()->DrawInstanced(3, 1, 0, 0);
}