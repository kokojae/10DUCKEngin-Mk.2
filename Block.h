#pragma once
#include "GameObject.h"

class Block : public GameObject
{
public:
	Block();
	~Block();

	void Init();
	void Update();
};

