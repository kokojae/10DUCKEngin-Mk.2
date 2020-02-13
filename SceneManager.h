#pragma once
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static enum class Scene
	{
		Main,InGame
	};

	static Scene current_scene;

	static void LoadScene(Scene scene, bool camera_clear = true);
};

