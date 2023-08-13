////#include "DirectXTex.h"
////#include "Texture1.h"
////
////DirectX::ScratchImage Texture::LoadTexture(const std::string& filePath) {
////	DirectX::ScratchImage image{};
////	std::wstring filePathW = ConvertString(filePath);
////	HRESULT hr = DirectX::LoadFromWICFile(filePathW.c_str(), DirectX::WIC_FLAGS_FORCE_SRGB, nullptr, image);
////	assert(SUCCEEDED(hr));
////
////	DirectX::ScratchImage mipImages{};
////	hr = DirectX::GenerateMipMaps(image.GetImage(), image.GetImageCount(), image.GetMetadata(), DirectX::TEX_FILTER_SRGB, 0, mipImages);
////	assert(SUCCEEDED(hr));
////
////	return mipImages;
////}
////ID3D12Resource* Texture::CreateTextureResource(ID3D12Device* decvice, const DirectX::TexMetadata& metadata) {
////	//metadataを基にResourceの設定
////	D3D12_RESOURCE_DESC resourceDesc{};
////	resourceDesc.Width = UINT(metadata.width);
////	resourceDesc.Height = UINT(metadata.height);
////	resourceDesc.MipLevels = UINT16(metadata.mipLevels);
////	resourceDesc.DepthOrArraySize = UINT16(metadata.arraySize);
////	resourceDesc.Format = metadata.format;
////	resourceDesc.SampleDesc.Count = 1;
////	resourceDesc.Dimension = D3D12_RESOURCE_DIMENSION(metadata.dimension);
////	//利用するHeapの設定
////	D3D12_HEAP_PROPERTIES heapProperties{};
////	heapProperties.Type = D3D12_HEAP_TYPE_CUSTOM;
////	heapProperties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_WRITE_BACK;
////	heapProperties.MemoryPoolPreference = D3D12_MEMORY_POOL_L0;
////	//Resourceを生成する
////	ID3D12Resource* resource = nullptr;
////	HRESULT hr = device->
////}
////void Texture::UploadTextureData(ID3D12Resource* resource, const DirectX::ScratchImage& mipImages) {
////
////}