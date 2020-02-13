#pragma once
#include "Layer.h"

class BoxCollider
{
public:
	BoxCollider();
	~BoxCollider();

	D3DXVECTOR2 size;
	D3DXVECTOR2 center;
	bool enable = true;
	int layer = Layer::DEFAULT;
};

