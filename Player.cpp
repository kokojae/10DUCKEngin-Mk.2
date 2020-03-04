#include "DXUT.h"
#include "Player.h"
#include "10DUCKEngine.h"

Player* Player::me = nullptr;

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	me = this;
	SetTexture(L"Source/player.png", { 100,100 });
	SetCollider({ 80,80 });
	z = -10;
	collider.layer = Layer::PLAYER;
}

void Player::Update()
{
	GetKey();
	Hspeed();
	Gravity();

	isClicked(MouseInput::lBtn);
}

void Player::LateUpdate()
{
	CameraMove();
}

void Player::GetKey()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		SceneManager::LoadScene(SceneManager::Scene::InGame);
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (hspeed > -5)
			hspeed -= 0.5f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (hspeed < 5)
			hspeed += 0.5f;
	}
	if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
	{
		hspeed -= hspeed / 20;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (PlaceMeeting({ 0,10 }, Layer::BLOCK))
		{
			SoundManager::PlaySFX(L"Source/Jump.wav");
			vspeed = -15;
		}
	}
	if (GetAsyncKeyState('D'))
		Camera::rotation += 5;
	if (GetAsyncKeyState('A'))
		Camera::rotation -= 5;
}

void Player::Hspeed()
{
	if (PlaceMeeting({ hspeed,0 }, Layer::BLOCK) != nullptr)
	{
		hspeed = 0;
	}
	else
	{
		position.x += hspeed;
	}
}

void Player::Gravity()
{
	vspeed += 0.5f;

	if (PlaceMeeting({ 0,vspeed }, Layer::BLOCK) != nullptr)
	{
		vspeed = 0;
	}
	else
	{
		position.y += vspeed;
	}
}

void Player::CameraMove()
{
	Camera::position += (position - Camera::position) / 30;
}
