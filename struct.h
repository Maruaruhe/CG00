#pragma once
#include "Vector4.h"
#include "Matrix4x4.h"

struct VertexData {
	Vector4 position;
	Vector2 texcoord;
	Vector3 normal;
};

struct TriangleData
{
	VertexData Left_;
	VertexData Top_;
	VertexData Right_;
};

struct Material {
	Vector4 color;
	int32_t enableLighting;
};