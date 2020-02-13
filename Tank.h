#pragma once
#include "GameObject.h"

class Tank : public GameObject
{
public:
	Tank();
	~Tank();

	float hspeed;
	float indexTime;

	void Init();
	void Update();
	void Render();
};

