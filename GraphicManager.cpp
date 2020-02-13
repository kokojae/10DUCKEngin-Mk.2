#include "DXUT.h"
#include "GraphicManager.h"
#include "10DUCKEngine.h"

LPD3DXSPRITE GraphicManager::sprite = nullptr;
ID3DXFont* GraphicManager::font = nullptr;

GraphicManager::GraphicManager()
{
}

GraphicManager::~GraphicManager()
{
}

void GraphicManager::Init()
{
	// 스프라이트 생성
	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);

	// 폰트 생성
	D3DXCreateFont(DXUTGetD3D9Device(), 70, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"맑은 고딕", &font);
}

void GraphicManager::Render()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	ObjectManager::Render();

	sprite->End();
}

void GraphicManager::Release()
{
	sprite->Release();
	font->Release();
}

void GraphicManager::TextureRender(TextureInfo info, D3DXVECTOR2 position)
{
	D3DXMATRIX mat, center, pos, scale, rotation;

	D3DXMatrixTranslation(&center, -info.center.x, -info.center.y, 0);
	D3DXMatrixTranslation(&pos, (int)position.x, (int)position.y, 0);
	D3DXMatrixScaling(&scale, info.scale.x, info.scale.y, 1);
	D3DXMatrixRotationZ(&rotation, D3DXToRadian(info.rotation));

	mat = center * scale * rotation * pos;

	if (info.camera_on == true)
		mat *= Camera::GetMatrix();
	
	sprite->SetTransform(&mat);

	// 도트겜일경우 사용
	//DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
	//DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
	//DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);

	RECT rect = { (LONG)(int)info.index * (LONG)info.size.x,0,(LONG)((int)info.index + 1) * (LONG)info.size.x,(LONG)info.size.y };

	sprite->Draw(info.texture, &rect, NULL, NULL, info.color);
}

void GraphicManager::TextRender(std::wstring text, D3DXVECTOR2 position, D3DXVECTOR2 scale, bool isUI)
{
	D3DXMATRIX mat, pos, scale_mat, rotation;

	D3DXMatrixTranslation(&pos, (int)position.x, (int)position.y, 0);
	D3DXMatrixScaling(&scale_mat, scale.x, scale.y, 1);

	mat = scale_mat * pos;

	if (!isUI)
		mat *= Camera::GetMatrix();

	sprite->SetTransform(&mat);

	font->DrawText(sprite, text.c_str(), -1, NULL, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
}
