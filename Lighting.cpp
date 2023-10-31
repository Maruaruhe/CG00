#include "Lighting.h"

void Lighting::Initialize() {
	directionalLight->color = { 1.0f,1.0f,1.0f,1.0f };
	directionalLight->direction = { 0.0f,-1.0f,0.0f };
	directionalLight->intensity = 1.0f;
}	