#pragma once
#include <iostream>
class CSoundManager;
class CSound;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	static CSoundManager* soundManager;

	static CSound* sound;

	static void Init();

	static void PlaySFX(std::wstring path, bool isBGM = false);
	static void EndSFX();
};

