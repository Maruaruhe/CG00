#pragma once
#include "Triangle.h"

struct SpriteData {
	VertexData LeftTop;
	VertexData LeftBot;
	VertexData RightTop;
	VertexData RightBot;
};

class Triangle;

class Sprite
{
public:
	void Initialize(DirectX12* directX12, SpriteData);

	void CreateVertexResource();

	void CreateVertexBufferView();

	void DataResource();

	void Release();

	void CreateMaterialResource();

	void CreateTransformationMatrixResource();

	void Update(Vector4& color, Transform& transform_);

	void Draw();
private:
	DirectX12* directX12_;

	Transform transform;
	Transform cameraTransform;

	//頂点リソース用のヒープの設定
	D3D12_HEAP_PROPERTIES uploadHeapProperties;
	//頂点リソースの設定
	D3D12_RESOURCE_DESC vertexResourceDesc;
	//実際に頂点リソースを作る
	ID3D12Resource* vertexResource;
	//頂点バッファビューを作成する
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView;

	//頂点リソースにデータを書き込む

	VertexData* vertexData;

	ID3D12Resource* materialResource_;

	Vector4* materialData_;

	ID3D12Resource* wvpResource_;
	Matrix4x4* wvpData;

	Transform transform_;
	Matrix4x4 worldMatrix_;

	const int32_t kClientWidth = 1080;
	const int32_t kClientHeight = 720;

};

