#pragma once
#include <string>
#include <d3d12.h>
#include "externals/DirectXTex/DirectXTex.h"

#include "DirectX12.h"
#include "Log.h"

class Texture
{
public:
	DirectX::ScratchImage LoadTexture(const std::string& filePath);
	ID3D12Resource* CreateTextureResource(ID3D12Device* decvice, const DirectX::TexMetadata& matadata);
	void UploadTextureData(ID3D12Resource* resource, const DirectX::ScratchImage& mipImages);

	ID3D12Resource* CreateDepthStencilTextureResource(ID3D12Device* device, int32_t width, int32_t height);
private:
	DirectX12* directX12_;
};

