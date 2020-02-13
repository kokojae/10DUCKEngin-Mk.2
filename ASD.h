#pragma once
#include "GameObject.h"

class ASD : public GameObject
{
public:
	ASD();
	~ASD();

	float t = 0;

	void Init();
	void Update();
	void Render();
};

