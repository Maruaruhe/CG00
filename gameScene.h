#pragma once
#include "DirectX12.h"
#include "GraphicsRenderer.h"
#include "WindowsAPI.h"
#include "Triangle.h"
#include "ImGuiWND.h"

#define MAXTRIANGLE 5 //三角形の最大数

class DirectX12;
class GraphicsRenderer;
class WindowsAPI;

class GameManager
{
public:



	/*void PreInit(GraphicsRenderer* graphicsRenderer);*/
	void Init(DirectX12* directX12, WindowsAPI* windowsAPI);
	void Update();
	void Release();



	void BeginFrame();

	void EndFrame();

	void Finalize();

	void Draw();

	void VariableInit();
private:
	TriangleData triangleData[MAXTRIANGLE];

	DirectX12* directX12_ = new DirectX12;
	GraphicsRenderer* graphicsRenderer_ = new GraphicsRenderer;
	Triangle** triangle_ = new Triangle * [MAXTRIANGLE];



	/*DirectX12* directX12;
	GraphicsRenderer* graphicsRenderer;
	WindowsAPI* windowsAPI;*/
};

