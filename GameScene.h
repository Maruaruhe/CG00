#pragma once
#include "DirectX12.h"
#include "Triangle.h"

class GameScene
{
public:
	void Initialize(WindowsAPI* winAPI, DirectX12* directX12, Triangle* triangle);
	void Update(DirectX12* directX12, Triangle* triangle);
	void Finish(DirectX12* directX12, Triangle* triangle);

	void DecideCommand(DirectX12* directX12, Triangle* triangle);
};

