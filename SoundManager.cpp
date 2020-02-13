#include "DXUT.h"
#include "SoundManager.h"
#include "10DUCKEngine.h"
#include "SDKsound.h"

CSoundManager* SoundManager::soundManager = nullptr;
CSound* SoundManager::sound = nullptr;

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

void SoundManager::PlayBGM(std::wstring path)
{
	soundManager->Create(&sound, const_cast<wchar_t*>(path.c_str()), 0, GUID_NULL);
	sound->Play(0, DSBPLAY_LOOPING);
}

void SoundManager::StopBGM()
{
	sound->Stop();
}

void SoundManager::EndBGM()
{
	sound->Stop();
	sound->Reset();
}

void SoundManager::PlaySFX(std::wstring path)
{
	soundManager->Create(&sound, const_cast<wchar_t*>(path.c_str()), 0, GUID_NULL);
	sound->Play(0, NULL);
}
