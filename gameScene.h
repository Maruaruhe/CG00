#pragma once
#include "DirectX12.h"
#include "GraphicsRenderer.h"
#include "WindowsAPI.h"
#include "Triangle.h"
#include "ImGuiWND.h"
#include "Texture.h"

#define TRIANGLECOUNT 3

class DirectX12;
class GraphicsRenderer;
class WindowsAPI;
class Texture;

class GameScene
{
public:
	void Initialize(DirectX12* directX12, WindowsAPI* windowsAPI);
	void Update();
	void Release();

	void BeginFrame();
	void EndFrame();
	void Final();
	void Draw();

	void VariableInit();
private:
	TriangleData triangleData[TRIANGLECOUNT];

	DirectX12* directX12_ = new DirectX12;
	GraphicsRenderer* graphicsRenderer_ = new GraphicsRenderer;
	Triangle** triangle_ = new Triangle * [TRIANGLECOUNT];
	//Texture* texture_ = new Texture;

	float colorVolume[3];
	Transform transform;
};

