#include "DirectXTexP.h"
#include "Texture.h"

DirectX::ScratchImage Texture::LoadTexture(const std::string& filePath) {
	DirectX::ScratchImage image{};
	std::wstring filePathW = ConvertString(filePath);
	HRESULT hr = DirectX::LoadFromWICFile(filePathW.c_str(), DirectX::WIC_FLAGS_FORCE_SRGB, nullptr, image);
	assert(SUCCEEDED(hr));

	DirectX::ScratchImage mipImages{};
	hr = DirectX::GenerateMipMaps(image.GetImage(), image.GetImageCount(), image.GetMetadata(), DirectX::TEX_FILTER_SRGB, 0, mipImages);
	assert(SUCCEEDED(hr));

	return mipImages;
}
ID3D12Resource* Texture::CreateTextureResource(ID3D12Device* decvice, const DirectX::TexMetadata& matadata) {
	//metadataを基にResourceの設定

	//利用するHeapの設定

	//Resourceを生成する

}
void Texture::UploadTextureData(ID3D12Resource* resource, const DirectX::ScratchImage& mipImages) {

}