#include "DXUT.h"
#include "MouseInput.h"
#include "10DUCKEngine.h"

bool MouseInput::lBtn = false;
bool MouseInput::rBtn = false;
bool MouseInput::mBtn = false;
bool MouseInput::sBtn1 = false;
bool MouseInput::sBtn2 = false;
int MouseInput::wheel = 0;
D3DXVECTOR2 MouseInput::pos = { 0,0 };
RECT MouseInput::rc = { 0,0,0,0 };

void MouseInput::Update()
{
	printf("X : %.f, Y : %.f\n", pos.x, pos.y);
	printf("%d, %d, %d, %d, %d\n", lBtn, rBtn, mBtn, sBtn1, sBtn2);

	if (wheel > 0)
		Camera::scale -= Camera::scale * 0.2;
	if (wheel < 0)
		Camera::scale += Camera::scale * 0.2;

	if (wheel > 0)
		wheel -= abs(wheel * 0.5); 
	if (wheel < 0)
		wheel += abs(wheel * 0.5);
}

RECT* MouseInput::GetRect()
{
	LONG x = static_cast<LONG>(pos.x);
	LONG y = static_cast<LONG>(pos.y);

	rc = { x,y,x,y };

	return &rc;
}
