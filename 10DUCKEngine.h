#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define WINDOWED true

// Component
#include "BoxCollider.h"
#include "TextureInfo.h"

// GameObject
// Base
#include "GameObject.h"
#include "Text.h"
// Object
#include "ASD.h"
#include "Block.h"
#include "Player.h"
#include "Tank.h"
#include "UIImage.h"

// Manager
#include "Camera.h"
#include "GraphicManager.h"
#include "Layer.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "TextureManager.h"

//�ܼ�â ����
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 

#define COLOR(a,r,g,b) (D3DCOLOR_ARGB(a, r, g, b))
#define TRANSPARENCY_COLOR(a) (D3DCOLOR_ARGB(a, 128, 128, 128))