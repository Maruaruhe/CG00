#include "gameScene.h"



void GameScene::Initialize(DirectX12* directX12, WindowsAPI* windowsAPI)
{
	VariableInit();
	directX12_ = directX12;
	directX12_->Init(windowsAPI);
	colorVolume[0] = 1.0f;
	colorVolume[1] = 1.0f;
	colorVolume[2] = 1.0f;

	graphicsRenderer_->Initialize(directX12);

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i] = new Triangle;
		triangle_[i]->Initialize(directX12_, triangleData[i]);
		//triangleSprite_[i]->Initialize(directX12_, spriteData[i]);
	}
	sphere->Initialize(directX12_);

	graphicsRenderer_->ViewportScissor();

	transform.translate = { 0.0f,0.0f,0.0f };
	transform.rotate = { 0.0f,0.0f,0.0f };
	transform.scale = { 1.0f,1.0f,1.0f };

	//texture_->scene(directX12);
}

void GameScene::Update() {
	//ImGui::ShowDemoWindow();

	ImGui::ColorEdit3("TriangleColor", colorVolume);
	ImGui::SliderFloat3("TriangleColor", colorVolume, 0.0f, 1.0f);
	ImGui::SliderFloat3("translate", &transform.translate.x, -1.5f, 1.5f);
	ImGui::SliderFloat3("rotate", &transform.rotate.x, -3.0f, 3.0f);
	ImGui::SliderFloat3("scale", &transform.scale.x, 0.0f, 10.0f);

	Vector4 color = {colorVolume[0],colorVolume[1],colorVolume[2],1.0f};

	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[0]->Update(color,transform);
		triangle_[1]->Update(color,transform);
		triangle_[2]->UpdateSprite(color,transform);
		triangle_[3]->UpdateSprite(color,transform);
		//triangleSprite_[i]->UpdateSprite(color,transform);
	}
	sphere->Update(color, transform);

	ImGui::Render();
}

void GameScene::Release() {
	directX12_->Release();
	graphicsRenderer_->Release();
	for (int i = 0; i < TRIANGLECOUNT; i++) {
		triangle_[i]->Release();
		//triangleSprite_[i]->Release();
	}
	sphere->Release();
}



void GameScene::BeginFrame() {
	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	directX12_->PreDraw();
	graphicsRenderer_->DecideCommand(directX12_);
}

void GameScene::EndFrame() {
	directX12_->PostDraw();
}

void GameScene::Final() {
	directX12_->ResourceLeakCheck();
}

void GameScene::Draw() {
	for (int i = 0; i < TRIANGLECOUNT; i++) {
		//triangle_[i]->Draw();
		//triangleSprite_[i]->Draw();
	}
	sphere->Draw();

}

void GameScene::VariableInit() {
	triangleData[0].Left_.position = { -0.5f,-0.5f,0.0f,1.0f };
	triangleData[0].Left_.texcoord = { 0.0f,1.0f };

	triangleData[0].Top_.position = { 0.0f,0.5f,0.0f,1.0f };
	triangleData[0].Top_.texcoord = { 0.5f,0.0f };

	triangleData[0].Right_.position = { 0.5f,-0.5f,0.0f,1.0f };
	triangleData[0].Right_.texcoord = { 1.0f,1.0f };

	//
	triangleData[1].Left_.position = { -0.5f,-0.5f,0.5f,1.0f };
	triangleData[1].Left_.texcoord = { 0.0f,1.0f };

	triangleData[1].Top_.position = { 0.0f,0.0f,0.0f,1.0f };
	triangleData[1].Top_.texcoord = { 0.5f,0.0f };

	triangleData[1].Right_.position = { 0.5f,-0.5f,-0.5f,1.0f };
	triangleData[1].Right_.texcoord = { 1.0f,1.0f };

	triangleData[2].Left_.position = { 0.0f,360.0f,0.0f,1.0f };
	triangleData[2].Left_.texcoord = { 0.0f,1.0f };
	triangleData[2].Top_.position = { 0.0f,0.0f,0.0f,1.0f };
	triangleData[2].Top_.texcoord = { 0.0f,0.0f };
	triangleData[2].Right_.position = { 640.0f,360.0f,0.0f,1.0f };
	triangleData[2].Right_.texcoord = { 1.0f,1.0f };

	triangleData[3].Left_.position = { 0.0f,0.0f,0.0f,1.0f };
	triangleData[3].Left_.texcoord = { 0.0f,0.0f };
	triangleData[3].Top_.position = { 640.0f,0.0f,0.0f,1.0f };
	triangleData[3].Top_.texcoord = { 1.0f,0.0f };
	triangleData[3].Right_.position = { 640.0f,360.0f,0.0f,1.0f };
	triangleData[3].Right_.texcoord = { 1.0f,1.0f };
}
