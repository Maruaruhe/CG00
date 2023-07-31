#pragma once
#include <string>
#include 

class Texture
{
public:
	DirectX::ScratchImage LoadTexture(const std::string& filePath);
	ID3D12Resource* CreateTextureResource(ID3D12Device* decvice, const DirectX::TexMetadata& matadata);
	void UploadTextureData(ID3D12Resource* resource, const DirectX::ScratchImage& mipImages);
private:

};

