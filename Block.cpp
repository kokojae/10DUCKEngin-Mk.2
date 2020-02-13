#include "DXUT.h"
#include "Block.h"
#include "10DUCKEngine.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::Init()
{
	SetTexture(L"Source/block.png", { 100,100 });
	SetCollider({ 100,100 });
	texture.color = COLOR(180, 255, 30, 0);
	collider.layer = Layer::BLOCK;
}

void Block::Update()
{
}
