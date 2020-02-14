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

		if (position.x < inst->position.x + inst->collider.size.x - inst->collider.center.x)
		if (position.x + size.x > inst->position.x - inst->collider.center.x)
		if (position.y < inst->position.y + inst->collider.size.y - inst->collider.center.y)
		if (position.y + size.y > inst->position.y - inst->collider.center.y)
			return inst;
	}
	return nullptr;
}

GameObject* ObjectManager::ColliderCheck(GameObject* obj, int layer)
{
	for (GameObject* inst : object_list)
	{
		if ((layer & inst->collider.layer) == 0)
			continue;
		if (inst->collider.enable == false)
			continue;
		if (inst->destroy)
			continue;

		RECT objRc, instRc;

		objRc.left = obj->position.x;
		objRc.right = obj->position.x + obj->collider.size.x;
		objRc.top = obj->position.y;
		objRc.bottom = obj->position.y + obj->collider.size.y;

		instRc.left = inst->position.x;
		instRc.right = inst->position.x + inst->collider.size.x;;
		instRc.left = inst->position.y;
		instRc.left = inst->position.y + inst->collider.size.y;

		if (IntersectRect(NULL, &objRc, &instRc))
			return inst;
	}
	return nullptr;
}
