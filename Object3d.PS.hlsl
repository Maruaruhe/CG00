#include "Object3d.hlsli"

struct Material {
	float32_t4 color;
};

ConstantBuffer<Material>gMaterial:register(b0);
struct PixelShaderOutput {
	float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input) {
Texture2D<float32_t4> gTexture : register(t0);
SampleState gSampler : register(s0);

float32_t4 textureColor = gTexture.Sample(gSample, input.texcoord);

	PixelShaderOutput output;
	output.color = gMaterial.color * textureColor;
	return output;
}