#pragma once
#include <iostream>
#include "TextureInfo.h"
#include "BoxCollider.h"
#include "ObjectManager.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	D3DXVECTOR2 position = { 0,0 };
	TextureInfo texture;
	BoxCollider collider;
	bool destroy = false;
	int z = 0;
	bool destroy_me = true;
	RECT* rect = new RECT();

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void DestroyMe();

	void DrawSelf();

	template <typename T>
	T* Instantiate(D3DXVECTOR2 position);

	GameObject* PlaceMeeting(D3DXVECTOR2 vector, int layer = Layer::DEFAULT);

	void SetTexture(std::wstring path, D3DXVECTOR2 texture_size);
	void SetCollider(D3DXVECTOR2 size);

	RECT* GetRect(D3DXVECTOR2 vector = { 0,0 });
};

template<typename T>
inline T* GameObject::Instantiate(D3DXVECTOR2 position = D3DXVECTOR2(0, 0))
{
	return ObjectManager::Instantiate<T>(position);
}
