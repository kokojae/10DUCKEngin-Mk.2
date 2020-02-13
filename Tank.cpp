#include "DXUT.h"
#include "Tank.h"
#include "10DUCKEngine.h"

Tank::Tank()
{
	hspeed = 0;
	indexTime = 0;
}

Tank::~Tank()
{
}

void Tank::Init()
{
	SetTexture(L"Source/tank.png", { 300,250 });
	SetCollider({ 200,80 });

	hspeed = 200;
	indexTime = 0;
}

void Tank::Update()
{
	indexTime += DXUTGetElapsedTime();
	if (indexTime >= 0.05)
	{
		indexTime = 0;
		texture.index++;
		if (texture.index > 3)
			texture.index = 0;
	}

	position.x += hspeed * DXUTGetElapsedTime();
}

void Tank::Render()
{
	DrawSelf();
	GraphicManager::TextRender(L"애니메이션 예시", position + D3DXVECTOR2(-60, -130), { 0.6,0.6 });
}
