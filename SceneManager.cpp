#include "DXUT.h"
#include "SceneManager.h"
#include "10DUCKEngine.h"
#include <time.h>

SceneManager::Scene SceneManager::current_scene;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(Scene scene, bool camera_clear)
{
	srand(time(NULL));
	current_scene = scene;
	if (camera_clear)
	{
		Camera::position = { 0,0 };
		Camera::rotation = 0;
		Camera::scale = 1;
	}

	ObjectManager::Clear();
	SoundManager::EndAllSFX();

	switch (scene)
	{
	case SceneManager::Scene::Main:
		SoundManager::PlaySFX(L"Source/test.wav", true);

		ObjectManager::Instantiate<UIImage>({ 1200,660 })->z = 10;	// 드로우 우선순위 설정

		ObjectManager::Instantiate<Text>({ 0,300 })->SetText(L"방향키 이동 WASD 카메라 조작\n씬이동 스페이스바", { 0.5,0.5 });
		ObjectManager::Instantiate<Text>({ 15,0 })->SetText(L"UI 텍스트 이렇게 쓰면됨", { 0.4,0.4 }, true);

		ObjectManager::Instantiate<Block>({ 0,200 });
		ObjectManager::Instantiate<Block>({ 100,200 });
		ObjectManager::Instantiate<Block>({ 200,200 });
		ObjectManager::Instantiate<Block>({ 300,100 });
		ObjectManager::Instantiate<Block>({ 400,200 });
		ObjectManager::Instantiate<Block>({ -100,100 });
		ObjectManager::Instantiate<Block>({ 0,-100 });;

		ObjectManager::Instantiate<Tank>()->position = { -500,-100 };

		ObjectManager::Instantiate<Player>();

		ObjectManager::Instantiate<ASD>()->position = { 200,-100 };
		break;
	case SceneManager::Scene::InGame:
		ObjectManager::Instantiate<Text>({ 0, -100 })->SetText(L"여기는 게임씬", { 0.5,0.5 });
		ObjectManager::Instantiate<ASD>();
		break;
	default:
		break;
	}
}
