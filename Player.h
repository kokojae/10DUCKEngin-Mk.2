#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	static Player* me;

	float vspeed = 0;
	float hspeed = 0;

	D3DXVECTOR2 camera_position;

	void Init();
	void Update();
	void LateUpdate();

	void GetKey();
	void Hspeed();
	void Gravity();
	void CameraMove();
};

