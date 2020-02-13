#pragma once
#include <iostream>
#include "TextureInfo.h"

class GraphicManager
{
public:
	GraphicManager();
	~GraphicManager();

	static LPD3DXSPRITE sprite;
	static ID3DXFont* font;

	static void Init();
	static void Render();
	static void Release();
	static void TextureRender(TextureInfo info, D3DXVECTOR2 position);
	static void TextRender(std::wstring text, D3DXVECTOR2 position, D3DXVECTOR2 scale = { 1,1 }, bool isUI = false);
};

