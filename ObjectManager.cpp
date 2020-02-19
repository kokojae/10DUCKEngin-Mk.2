#include "DXUT.h"
#include "ObjectManager.h"
#include "10DUCKEngine.h"

std::list<GameObject*> ObjectManager::object_list = std::list<GameObject*>();
std::list<GameObject*> ObjectManager::collider_list = std::list<GameObject*>();

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

bool ObjectManager::Sort(const GameObject* a, const GameObject* b)
{
	return a->z > b->z;
}

void ObjectManager::Update()
{
	std::list<GameObject*>::iterator it = object_list.begin();

	while (it != object_list.end())
	{
		GameObject* inst = it._Ptr->_Myval;

		if (inst->destroy)
		{
			if (inst->destroy_me)
				inst->DestroyMe();
			collider_list.remove(inst);
			object_list.erase(it++);
			delete(inst);
			continue;
		}

		inst->Update();
		it++;
	}
}

void ObjectManager::LateUpdate()
{
	for (GameObject* inst : object_list)
	{
		if (inst->destroy)
			continue;
		inst->LateUpdate();
	}
}

void ObjectManager::Render()
{
	for (GameObject* inst : object_list)
	{
		if (inst->destroy)
			continue;
		inst->Render();
	}
}

void ObjectManager::Release()
{
	TextureManager::ReleaseTexture();
}

void ObjectManager::Clear()
{
	for (GameObject* inst : object_list)
	{
		inst->destroy = true;
		inst->destroy_me = false;
	}
}

GameObject* ObjectManager::ColliderCheck(D3DXVECTOR2 position, D3DXVECTOR2 size, int layer)
{
	for (GameObject* inst : object_list)
	{
		if ((layer & inst->collider.layer) == 0)
			continue;
		if (inst->collider.enable == false)
			continue;
		if (inst->destroy)
			continue;

		RECT rc, orc, irc;

		orc.left = position.x;
		orc.right = position.x + size.x;
		orc.top = position.y;
		orc.bottom = position.y + size.x;

		irc.left = inst->position.x - inst->collider.center.x;
		irc.right = inst->position.x + inst->collider.size.x - inst->collider.center.x;
		irc.top = inst->position.y - inst->collider.center.y;
		irc.bottom = inst->position.y + inst->collider.size.y - inst->collider.center.y;

		if (IntersectRect(&rc, &orc, &irc))
			return inst;

		// 임시객체의 포인터 주소를 놈겨도 실행이됨
		//if (IntersectRect(&RECT(), &orc, &irc))
		//	return inst;

		// NULL또는 nullptr을 매개변수로 넘기면 실행이 되지않음
		//if (IntersectRect(NULL, &orc, &irc))
		//	return inst;
		//if (IntersectRect(nullptr, &orc, &irc))
		//	return inst;

		//if (position.x < inst->position.x + inst->collider.size.x - inst->collider.center.x)
		//if (position.x + size.x > inst->position.x - inst->collider.center.x)
		//if (position.y < inst->position.y + inst->collider.size.y - inst->collider.center.y)
		//if (position.y + size.y > inst->position.y - inst->collider.center.y)
		//	return inst;
	}
	return nullptr;
}
