#pragma once
#include "Vector4.h"
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <string>
#include <format>
#include <dxgidebug.h>
#include <dxcapi.h>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dxcompiler.lib")

class Triangle
{
public:
	void LogText(const std::string& message);
	void InitializeDXC();

	IDxcBlob* CompileShader(
		const std::wstring& filepath,
		const wchar_t* profile,
		IDxcUtils* dxcUtiles,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler
	);

	void MakeRootSignature();
	void SetInputLayout();
	void SetBlendState();
	void SetRasterizerState();
	void ShaderCompile();
	void MakePSO();
	void MakeVertexResource();
	void MakeVertexBufferView();
	void DateResource();
	void ViewportScissor();
private:
	HRESULT hr;
	//InitializeDXC
	IDxcUtils* dxcUtils;
	IDxcCompiler3* dxcCompiler;
	IDxcIncludeHandler* includeHandler;
	//MakeRootSignature
	D3D12_ROOT_SIGNATURE_DESC descriptionRootSignature{};
	ID3DBlob* signatureBlob;
	ID3DBlob* errorBlob;
	ID3D12RootSignature* rootSignature;
	//SetInputLayout
	D3D12_INPUT_ELEMENT_DESC inputElementDescs[1];
	D3D12_INPUT_LAYOUT_DESC inputLayoutDesc{};
	//SetBlendState
	D3D12_BLEND_DESC blendDesc{};
	//SetRasterizerState
	D3D12_RASTERIZER_DESC rasterizerDesc{};
	//ShaderCompile
	IDxcBlob* vertexShaderBlob;
	IDxcBlob* pixelShaderBlob;
	//MakePSO
	D3D12_GRAPHICS_PIPELINE_STATE_DESC graphicsPipelineStateDesc{};
	ID3D12PipelineState* graphicsPipelineState;
	//MakeVertexResource
	D3D12_HEAP_PROPERTIES uploadHeapProperties{};
	D3D12_RESOURCE_DESC vertexResourceDesc{};
	ID3D12Resource* vertexResource;
	//MakeVertexBufferView
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};
	//DateResource
	Vector4* vertexDate;
	//ViewportScissor
	D3D12_VIEWPORT viewport{};
	D3D12_RECT scissorRect{};
};

