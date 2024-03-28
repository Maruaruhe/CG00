#pragma once
#include "DirectXGame/Base/DirectX12/DirectX12.h"
#include "DirectXGame/Base//GraphicsRenderer/GraphicsRenderer.h"
#include "DirectXGame/Base/WindowsAPI/WindowsAPI.h"
#include "DirectXGame/Base/ImGui/ImGuiWND.h"
#include "DirectXGame/Object/Triangle/Triangle.h"
#include "DirectXGame/Object/Texture/Texture.h"
#include "DirectXGame/Object/Sphere/Sphere.h"
#include "DirectXGame/Object/Light/Lighting.h"
#include "DirectXGame/Object/Sprite/Sprite.h"
#include "DirectXGame/Object/Model/Model.h"

#define TRIANGLECOUNT 2

class DirectX12;
class GraphicsRenderer;
class WindowsAPI;
class Texture;
class Sphere;
class Lighting;

class GameScene
{
public:
	void Initialize();
	void Update();
	void Release();

	void BeginFrame();
	void EndFrame();
	void Final();
	void Draw();

	void VariableInit();
private:
	TriangleData triangleData[TRIANGLECOUNT];
	SpriteData spriteData;

	DirectX12* directX12_ = nullptr;

	GraphicsRenderer* graphicsRenderer_ = new GraphicsRenderer;
	Triangle** triangle_ = new Triangle * [TRIANGLECOUNT];
	Sprite* sprite = new Sprite;
	//Texture* texture_ = new Texture;
	Sphere* sphere = new Sphere;
	Model* model = new Model;

	DirectionalLight light;

	float colorVolume[3];
	Transform transform;
};

