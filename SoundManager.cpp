#include "DXUT.h"
#include "SoundManager.h"
#include "10DUCKEngine.h"
#include "SDKsound.h"

CSoundManager* SoundManager::soundManager = nullptr;
std::map<std::wstring, CSound*> SoundManager::sound_map = std::map<std::wstring, CSound*>();

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

void SoundManager::Init()
{
	soundManager = new CSoundManager;
	soundManager->Initialize(DXUTGetHWND(), DSSCL_PRIORITY);
	soundManager->SetPrimaryBufferFormat(2, 22050, 16);
}

CSound* SoundManager::SearchSFX(std::wstring path)
{
	CSound* SFX;

	if (sound_map.count(path))
	{
		SFX = sound_map.find(path)->second;
	}
	else
	{
		soundManager->Create(&SFX, const_cast<wchar_t*>(path.c_str()), 0, GUID_NULL);

		sound_map[path] = SFX;
	}

	return SFX;
}

void SoundManager::PlaySFX(std::wstring path, bool isBGM)
{
	CSound* SFX = SearchSFX(path);

	if (isBGM)
		SFX->Play(0, DSBPLAY_LOOPING);
	else
	{
		SFX->Reset();
		SFX->Play(0, NULL);
	}


	return;
}

void SoundManager::EndSFX(std::wstring path)
{
	if (sound_map.count(path))
	{
		sound_map.find(path)->second->Stop();
		sound_map.find(path)->second->Reset();
	}
	return;
}

void SoundManager::EndAllSFX()
{
	std::map<std::wstring, CSound*>::iterator it = sound_map.begin();

	while (it != sound_map.end())
	{
		it->second->Stop();
		it->second->Reset();
		it++;
	}
}
