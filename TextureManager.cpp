#include "DXUT.h"
#include "TextureManager.h"
#include "10DUCKEngine.h"

std::map<std::wstring, LPDIRECT3DTEXTURE9>TextureManager::texture_map = std::map<std::wstring, LPDIRECT3DTEXTURE9>();

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

LPDIRECT3DTEXTURE9 TextureManager::LoadTexture(std::wstring path)
{
	LPDIRECT3DTEXTURE9 texture;

	if (texture_map.count(path))
	{
		texture = texture_map.find(path)->second;
	}
	else
	{
		D3DXCreateTextureFromFileEx(
			DXUTGetD3D9Device(),
			path.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			1,
			0,
			D3DFMT_A8R8G8B8,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_DEFAULT,
			0,
			NULL,
			NULL,
			&texture);

		texture_map[path] = texture;
	}
	return texture;
}

void TextureManager::ReleaseTexture()
{
	std::map<std::wstring, LPDIRECT3DTEXTURE9>::iterator it = texture_map.begin();

	while (it != texture_map.end())
	{
		it->second->Release();
		texture_map.erase(it++);
	}
}
