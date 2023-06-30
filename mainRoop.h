#pragma once
#include "WindowsAPI.h"
#include "DirectX12.h"
#include "GraphicsRenderer.h"
#include "Triangle.h"
#define TRIANGLECOUNT 1

class WindowsAPI;
class GraphicsRenderer;
class DirectX12;

class MainRoop
{
public:
	void Initialize(WindowsAPI* winAPI,DirectX12* directX12);
	void Update();
	void Release();
	void Draw();

	void First();
	void Final();

	void End();

	void VariableInit();

	void camera();

private:
	struct TriangleData
	{
		Vector4 leftBot_;
		Vector4 middleTop_;
		Vector4 rightBot_;
	};

	TriangleData triangleData[TRIANGLECOUNT];

	DirectX12* directX12_ = new DirectX12;
	GraphicsRenderer* graphicsRenderer_ = new GraphicsRenderer;
	Triangle* triangle_[TRIANGLECOUNT];

	Matrix4x4 cameraMatrix;
	Matrix4x4 viewMatrix;
	Matrix4x4 projectionMatrix;
	Matrix4x4 worldViewProjectionMatrix;
};