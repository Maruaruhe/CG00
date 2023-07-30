#include "Triangle.h"

void Triangle::Initialize(DirectX12* directX12){
	directX12_ = directX12;
	transform = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	MakeVertexResource();
	MakeMaterialResource();
	MakeVertexBufferView();
	MakeWvpResource();
	DateResource();
}

void Triangle::Update() {
	transform.rotate.y += 0.03f;
	Matrix4x4 worldMatrix = MakeAffineMatrix(transform.scale, transform.rotate, transform.translate);
	*wvpDate = worldMatrix;
	//*wvpDate = camera->MakeWVPMatrix(transform);
}

void Triangle::MakeVertexResource() {
	vertexResource = directX12_->CreateBufferResource(directX12_->GetDevice(), sizeof(Vector4) * 3);
}

void Triangle::MakeMaterialResource() {
	materialResource = directX12_->CreateBufferResource(directX12_->GetDevice(), sizeof(Vector4));

	materialDate = nullptr;

	materialResource->Map(0, nullptr, reinterpret_cast<void**>(&materialDate));

	*materialDate = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
}

void Triangle::MakeWvpResource() {
	wvpResource = directX12_->CreateBufferResource(directX12_->GetDevice(), sizeof(Matrix4x4));

	wvpDate = nullptr;

	wvpResource->Map(0, nullptr, reinterpret_cast<void**>(&wvpDate));

	*wvpDate = MakeIdentity4x4();
}

void Triangle::MakeResource() {

}

void Triangle::MakeVertexBufferView() {
	vertexBufferView = {};
	vertexBufferView.BufferLocation = vertexResource->GetGPUVirtualAddress();
	vertexBufferView.SizeInBytes = sizeof(Vector4) * 3;
	vertexBufferView.StrideInBytes = sizeof(Vector4);
}
void Triangle::DateResource(){
	vertexResource->Map(0, nullptr, reinterpret_cast<void**>(&vertexDate));
}
void Triangle::AllReleasse() {
	vertexResource->Release();
	materialResource->Release();
}

void Triangle::Draw(Vector4 leftBot, Vector4 midTop, Vector4 rightBot) {
	//左下
	vertexDate[0] = leftBot;
	//上
	vertexDate[1] = midTop;
	//右下
	vertexDate[2] = rightBot;

	directX12_->GetCommandList()->IASetVertexBuffers(0, 1, &vertexBufferView);
	directX12_->GetCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	directX12_->GetCommandList()->SetGraphicsRootConstantBufferView(0, materialResource->GetGPUVirtualAddress());
	directX12_->GetCommandList()->SetGraphicsRootConstantBufferView(1, wvpResource->GetGPUVirtualAddress());
	directX12_->GetCommandList()->DrawInstanced(3, 1, 0, 0);
}