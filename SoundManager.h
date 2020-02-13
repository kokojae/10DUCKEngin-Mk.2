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

	static void PlayBGM(std::wstring path);
	static void StopBGM();
	static void EndBGM();

	static void PlaySFX(std::wstring path);
};

