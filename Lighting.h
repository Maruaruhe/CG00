#pragma once
#include "Vector4.h"

struct DirectionalLight {
	Vector4 color;
	Vector3 direction;
	float intensity;
};

class Lighting
{
private:
	void Initialize();
public:
	DirectionalLight* directionalLight;
};

