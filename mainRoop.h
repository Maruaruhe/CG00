#pragma once
#include "WindowsAPI.h"
#include "DirectX12.h"
#include "GraphicsRenderer.h"
#include "Triangle.h"

class MainRoop
{
public:
	int TriangleCount = 2;
	WindowsAPI* windowsAPI = new WindowsAPI;
	DirectX12* directX12 = new DirectX12;
	GraphicsRenderer* graphicsRenderer1 = new GraphicsRenderer;
	GraphicsRenderer* graphicsRenderer2 = new GraphicsRenderer;
	//Triangle** triangle = new Triangle*[TriangleCount];
	

	void Initialize(WindowsAPI* winAPI,DirectX12* directX12/*,GraphicsRenderer* graphicsRenderer*//*,Triangle* drawTriangle*/);
	void Update(DirectX12* directX12);
	void End(WindowsAPI* winAPI, DirectX12* directX12/*, GraphicsRenderer* graphicsRenderer*//*, DrawTriangle* drawTriangle*/);
};