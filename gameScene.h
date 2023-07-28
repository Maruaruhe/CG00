#pragma once
#include "WindowsAPI.h"
#include "DirectX12.h"
#include "GraphicsRenderer.h"
#include "Triangle.h"
#define TRIANGLECOUNT 2

class WindowsAPI;
class GraphicsRenderer;
class DirectX12;

class GameScene
{
public:
	void Initialize(WindowsAPI* winAPI,DirectX12* directX12);
	void Update();
	void Release();
	void Draw();

	void PreDraw();
	void Final();

	void End();

	void VariableInit();

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
};