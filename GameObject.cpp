#include "DXUT.h"
#include "GameObject.h"
#include "10DUCKEngine.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
}

void GameObject::Update()
{
}

void GameObject::LateUpdate()
{
}

void GameObject::Render()
{
	DrawSelf();
}

void GameObject::DestroyMe()
{
	delete rect;
}

void GameObject::DrawSelf()
{
	GraphicManager::TextureRender(texture, position);
}

GameObject* GameObject::PlaceMeeting(D3DXVECTOR2 vector, int layer)
{
	collider.enable = false;

	SetRect(vector);
	GameObject* inst = ObjectManager::ColliderCheck(rect, layer);

	collider.enable = true;

	return inst;
}

void GameObject::SetTexture(std::wstring path, D3DXVECTOR2 texture_size)
{
	texture.texture = TextureManager::LoadTexture(path);
	texture.size = texture_size;
	texture.center = texture_size / 2;
}

void GameObject::SetCollider(D3DXVECTOR2 size)
{
	collider.size = size;
	collider.center = size / 2;

	ObjectManager::collider_list.push_back(this);
}

void GameObject::SetRect(D3DXVECTOR2 vector)
{
	if (rect == nullptr)
	{
		rect = new RECT{
			static_cast<LONG>((position - collider.center + vector).x),
			static_cast<LONG>((position - collider.center + vector + collider.size).x),
			static_cast<LONG>((position - collider.center + vector).y),
			static_cast<LONG>((position - collider.center + vector + collider.size).y)
		};
	}
	else
	{
		rect->left		= (position - collider.center + vector).x;
		rect->right		= (position - collider.center + vector + collider.size).x;
		rect->top		= (position - collider.center + vector).y;
		rect->bottom	= (position - collider.center + vector + collider.size).y;
	}
}
