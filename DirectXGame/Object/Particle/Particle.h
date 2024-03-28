#pragma once
#include <fstream>
#include <sstream>
#include <stdint.h>
#include <vector>
#include "../../Base/DirectX12/DirectX12.h"
#include <dxcapi.h>
#include "../../Math/struct.h"
#include "../../Math/Matrix4x4.h"
#include "../../Math/Vector4.h"
#include "../Light/Lighting.h"

#define kNumInstance 15
#pragma comment(lib,"dxcompiler.lib")

class Particle
{
public:
	ModelData LoadObjFile(const std::string& directoryPath, const std::string& filename);

	void Initialize(DirectX12* directX12);

	void InitializePosition();

	void CreateVertexResource();

	void CreateSRV();

	void Release();

	void CreateMaterialResource();

	void CreateInstance();

	void CreateTransformationMatrixResource();

	void CreateDirectionalLightResource();

	void Update(Vector4& color, Transform& transform_, DirectionalLight& directionalLight);

	void Draw();

	MaterialData LoadMaterialTemplateFile(const std::string& directoryPath, const std::string& filename);

private:
	DirectX12* directX12_;
	ModelData modelData;

	Transform cameraTransform;

	//頂点リソース用のヒープの設定
	D3D12_HEAP_PROPERTIES uploadHeapProperties;
	//頂点リソースの設定
	D3D12_RESOURCE_DESC vertexResourceDesc;
	//実際に頂点リソースを作る
	Microsoft::WRL::ComPtr<ID3D12Resource> vertexResource;
	Microsoft::WRL::ComPtr<ID3D12Resource> instancingResource;

	//頂点バッファビューを作成する
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView;

	//頂点リソースにデータを書き込む

	Microsoft::WRL::ComPtr<ID3D12Resource> materialResource_;

	Material* materialData_;

	Microsoft::WRL::ComPtr<ID3D12Resource> wvpResource_;

	DirectionalLight* directionalLight_;
	Microsoft::WRL::ComPtr<ID3D12Resource> directionalLightResource;

	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;

	bool useMonsterBall = true;

private:
	//SpriteData spData[256];
	VertexData* vertexData;

	float num = 0.0625f;
	const float pi = 3.14f;
	Transform transforms[kNumInstance];
	TransformationMatrix* instancingData;

	uint32_t descriptorSizeSRV{};

	D3D12_CPU_DESCRIPTOR_HANDLE instancingSrvHandleCPU;
	D3D12_GPU_DESCRIPTOR_HANDLE instancingSrvHandleGPU;

	//const int kNumInstance = 10;
};