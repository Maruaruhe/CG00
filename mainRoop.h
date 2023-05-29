#pragma once
#include "WindowsAPI.h"
#include "DirectX12.h"
#include "Triangle.h"

class MainRoop
{
public:
	WindowsAPI* windowsAPI = new WindowsAPI;
	DirectX12* directX12 = new DirectX12;
	Triangle* triangle = new Triangle;

	void Initialize(WindowsAPI* winAPI,DirectX12* directX12,Triangle* triangle);
	void Update(DirectX12* directX12,Triangle* triangle);
	void End(WindowsAPI* winAPI, DirectX12* directX12, Triangle* triangle);
};