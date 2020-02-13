#include "DXUT.h"
#include "ASD.h"
#include "10DUCKEngine.h"

ASD::ASD()
{
}

ASD::~ASD()
{
}

void ASD::Init()
{
	SetTexture(L"Source/block.png", { 100,100 });
}

void ASD::Update()
{
	t += 0.15f;

	texture.rotation = sin(t / 4) * 80;
	texture.scale = { 0.5f + sin(t) * 0.1f,0.5f + sin(t + 10) * 0.1f };

	position.y += sin(t / 4);

	D3DXCOLOR* a = new D3DXCOLOR(COLOR(180, 0, 60, 255));
	D3DXCOLOR* b = new D3DXCOLOR(COLOR(180, 60, 255, 0));

	D3DXColorLerp(&texture.color, a, b, 0.5 + sin(t / 3) * 0.5);
}

void ASD::Render()
{
	DrawSelf();
	GraphicManager::TextRender(L"hjine01.blog.me", position + D3DXVECTOR2(30, 0));
}
