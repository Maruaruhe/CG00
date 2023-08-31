#include "Triangle.h"

void Triangle::Initialize(DirectX12* directX12, TriangleData triangleData) {
	directX12_ = directX12;
	transform = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	cameraTransform = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,-5.0f} };
	CreateVertexResource();
	CreateMaterialResource();
	CreateVertexBufferView();
	CreateTransformationMatrixResource();
	DataResource();

	//左下
	//vertexData[0] = triangleData.Left_;
	//上
	//vertexData[1] = triangleData.Top_;
	//右下
	//vertexData[2] = triangleData.Right_;

	vertexData = nullptr;

	vertexResource->Map(0, nullptr, reinterpret_cast<void**>(&vertexData));
	vertexData[0].position = { -0.5f,-0.5f,0.0f,1.0f };
	vertexData[0].texcoord = { 0.0f,1.0f };

	vertexData[1].position = { 0.0f,0.5f,0.0f,1.0f };
	vertexData[1].texcoord = { 0.5f,0.0f };

	vertexData[2].position = { 0.5f,-0.5f,0.0f,1.0f };
	vertexData[2].texcoord = { 1.0f,1.0f };
}

void Triangle::Update(Vector4& color,Transform& transform_) {
	transform.translate = transform_.translate;
	transform.rotate = transform_.rotate;
	transform.scale = transform_.scale;
	Matrix4x4 worldMatrix = MakeAffineMatrix(transform.scale, transform.rotate, transform.translate);
	Matrix4x4 cameraMatrix = MakeAffineMatrix(cameraTransform.scale, cameraTransform.rotate, cameraTransform.translate);
	Matrix4x4 viewMatrix = Inverse(cameraMatrix);
	Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kClientWidth) / float(kClientHeight), 0.1f, 100.0f);
	Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
	*wvpData = worldViewProjectionMatrix;
	//worldMatrix_ = MakeAffineMatrix(transform_.scale, transform_.rotate, transform_.translate);
	//*wvpData = worldMatrix_;
//	*materialData_ = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	*materialData_ = color;
}

void Triangle::Draw() {
	directX12_->GetCommandList()->IASetVertexBuffers(0, 1, &vertexBufferView);	//VBVを設定
	//形状を設定。PSOに設定しているものとはまた別。同じものを設定すると考えておけばよい
	directX12_->GetCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	directX12_->GetCommandList()->SetGraphicsRootConstantBufferView(0, materialResource_->GetGPUVirtualAddress());
	D3D12_GPU_DESCRIPTOR_HANDLE textureSrvHandleGPU = directX12_->GetSrvDescriptorHeap()->GetGPUDescriptorHandleForHeapStart();
	directX12_->GetCommandList()->SetGraphicsRootDescriptorTable(2, textureSrvHandleGPU);
	//wvp用のCBufferの場所を設定
	directX12_->GetCommandList()->SetGraphicsRootConstantBufferView(1, wvpResource_->GetGPUVirtualAddress());
	//描画！　（DrawCall/ドローコール)。3頂点で1つのインスタンス。インスタンスについては今後
	directX12_->GetCommandList()->DrawInstanced(3, 1, 0, 0);
}

void Triangle::CreateVertexResource() {
	vertexResource = directX12_->CreateBufferResource(directX12_->GetDevice(), sizeof(Vector4) * 3);
}

void Triangle::CreateVertexBufferView() {
	vertexBufferView = {};
	//リソースの先頭のアドレスから使う
	vertexBufferView.BufferLocation = vertexResource->GetGPUVirtualAddress();
	//使用するリソースのサイズは頂点３つ分のサイズ
	vertexBufferView.SizeInBytes = sizeof(Vector4) * 3;
	//1頂点当たりのサイズ
	vertexBufferView.StrideInBytes = sizeof(Vector4);
}

void Triangle::CreateMaterialResource() {
	materialResource_ = directX12_->CreateBufferResource(directX12_->GetDevice(), sizeof(Vector4));
	materialData_ = nullptr;
	materialResource_->Map(0, nullptr, reinterpret_cast<void**>(&materialData_));
	*materialData_ = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
}

void Triangle::CreateTransformationMatrixResource() {
	//WVP用のリソースを作る。Matrix4x4　1つ分のサイズを用意する
	wvpResource_ = directX12_->CreateBufferResource(directX12_->GetDevice(), sizeof(Matrix4x4));
	//データを書き込む
	wvpData = nullptr;
	//書き込むためのアドレスを取得
	wvpResource_->Map(0, nullptr, reinterpret_cast<void**>(&wvpData));
	//単位行列を書き込んでおく
	*wvpData = MakeIdentity4x4();
}

void Triangle::DataResource() {
	//書き込むためのアドレスを取得
	vertexResource->Map(0, nullptr, reinterpret_cast<void**>(&vertexData));
}

void Triangle::Release() {
	vertexResource->Release();
	materialResource_->Release();
}