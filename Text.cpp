#include "DXUT.h"
#include "Text.h"
#include "10DUCKEngine.h"

Text::Text()
{
}

Text::~Text()
{
}

void Text::Render()
{
	GraphicManager::TextRender(text.c_str(), position, scale, isUI);
}

void Text::SetText(std::wstring text, D3DXVECTOR2 scale, bool isUI)
{
	this->text = text;
	this->scale = scale;
	this->isUI = isUI;
}
