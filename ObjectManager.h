#pragma once
#include <list>
#include "Layer.h"
class GameObject;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	static std::list<GameObject*> object_list;
	static std::list<GameObject*> collider_list;

	template <typename T>
	static T* Instantiate(D3DXVECTOR2 position = { 0,0 });

	static bool Sort(const GameObject* a, const GameObject* b);

	static void Update();
	static void LateUpdate();
	static void Render();
	static void Release();
	static void Clear();

	static GameObject* ColliderCheck(D3DXVECTOR2 position, D3DXVECTOR2 size, int layer = Layer::DEFAULT);
};

template<typename T>
inline T* ObjectManager::Instantiate(D3DXVECTOR2 position)
{
	T* inst = new T;

	object_list.push_back(inst);
	inst->Init();
	inst->position = position;
	object_list.sort(Sort);

	return inst;
}
