#pragma once
#include "WindowsAPI.h"
#include "DirectX12.h"

class GameScene
{
public:
	void Initialize();

	void Update();

private:
	void PreDraw();

	void PostDraw();

private:
	WindowsAPI* winAPI_ = new WindowsAPI();
	DirectX12* directX_ = new DirectX12();
};

