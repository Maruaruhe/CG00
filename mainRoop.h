#pragma once
#include "WindowsAPI.h"
#include "DirectX12.h"
#include "GraphicsRenderer.h"
#include "Triangle.h"

class MainRoop
{
public:
	WindowsAPI* windowsAPI = new WindowsAPI;
	DirectX12* directX12 = new DirectX12;
	GraphicsRenderer* graphicsRenderer = new GraphicsRenderer;
	Triangle* triangle1 = new Triangle;
	Triangle* triangle2 = new Triangle;
	

	void Initialize(WindowsAPI* winAPI,DirectX12* directX12,GraphicsRenderer* graphicsRenderer,Triangle* drawTriangle);
	void Update(DirectX12* directX12,GraphicsRenderer* graphicsRenderer);
	void End(WindowsAPI* winAPI, DirectX12* directX12, GraphicsRenderer* graphicsRenderer/*, DrawTriangle* drawTriangle*/);
};