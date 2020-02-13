#pragma once
#include <iostream>
#include <map>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static std::map<std::wstring, LPDIRECT3DTEXTURE9> texture_map;

	static LPDIRECT3DTEXTURE9 LoadTexture(std::wstring path);
	static void ReleaseTexture();
};

