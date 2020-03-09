#pragma once
#include <iostream>
#include <map>+
class CSoundManager;
class CSound;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	static CSoundManager* soundManager;

	static std::map<std::wstring, CSound*>sound_map;

	static void Init();

	static CSound* SearchSFX(std::wstring path);
	static void PlaySFX(std::wstring path, bool isBGM = false);
	static void EndSFX(std::wstring path);
	static void EndAllSFX();
};

