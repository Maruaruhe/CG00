#pragma once
#include <string>
#include "Log.h"
#include <d3d12.h>
#include "DirectX12.h"
#include "externals/DirectXTex/DirectXTex.h"

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"dxguid.lib")

class Texture
{
public:
	DirectX::ScratchImage LoadTexture(const std::string& filePath);
	ID3D12Resource* CreateTextureResource(ID3D12Device* decvice, const DirectX::TexMetadata& matadata);
	void UploadTextureData(ID3D12Resource* resource, const DirectX::ScratchImage& mipImages);
	void LoadAndExport();
	void scene(DirectX12* directX12);

private:
	DirectX12* directX12_;
	//DirectX::ScratchImage mipImages;
	//const DirectX::TexMetadata& metadata;
 //   ID3D12Resource* textureResource;
};
