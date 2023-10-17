#pragma once
#include <stdint.h>
#include "Triangle.h"

class Triangle;

struct SpriteData {
	TriangleData first;
	TriangleData second;
};

class Sphere
{
public:
	void Draw();
private:
	SpriteData spData[256];

	const float pi = 3.14f;
};

