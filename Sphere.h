#pragma once
#include <stdint.h>
#include "Triangle.h"

struct SpriteData {
	TriangleData first;
	TriangleData second;
};

struct Material {
	Vector4 color;
	int32_t enableLighting;
};

class Sphere
{
public:
	void Initialize(DirectX12* directX12);

	void InitializePosition();

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
	ID3D12Resource* materialResourceSprite;
	//頂点バッファビューを作成する
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView;

	//頂点リソースにデータを書き込む
	//Vector4* vertexData;

	//VertexData* vertexData;

	ID3D12Resource* materialResource_;

	Vector4* materialData_;

	ID3D12Resource* wvpResource_;
	Matrix4x4* wvpData;

	Transform transform_;
	Matrix4x4 worldMatrix_;

	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;

	bool useMonsterBall = true;

private:
	SpriteData spData[256];
	VertexData* vertexData;

	float num = 0.0625f;
	const float pi = 3.14f;
};

