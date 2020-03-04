#pragma once
class MouseInput
{
public:
	static bool lBtn;
	static bool rBtn;
	static bool mBtn;
	static bool sBtn1;
	static bool sBtn2;
	static int wheel;
	static D3DXVECTOR2 pos;

	static RECT rc;

	static void Update();

	static RECT* GetRect();
};

