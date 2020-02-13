#include "DXUT.h"
#include "UIImage.h"
#include "10DUCKEngine.h"

UIImage::UIImage()
{
}

UIImage::~UIImage()
{
}

void UIImage::Init()
{
	SetTexture(L"Source/uiimage.png", { 150,100 });
	texture.camera_on = false;
	z = -100;
}

void UIImage::Update()
{
}
