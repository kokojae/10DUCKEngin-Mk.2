#include "DXUT.h"
#include "Camera.h"
#include "10DUCKEngine.h"

D3DXVECTOR2 Camera::position = { 0,0 };
float Camera::scale = 1;
float Camera::rotation = 0;
D3DXVECTOR2 Camera::shake = { 1,1 };

Camera::Camera()
{
}

Camera::~Camera()
{
}

D3DXMATRIX Camera::GetMatrix()
{
	D3DXMATRIX mat, mat_rotation, mat_scale, mat_position, screen;

	D3DXMatrixTranslation(&mat_position, -position.x, -position.y, 0);
	D3DXMatrixRotationZ(&mat_rotation, D3DXToRadian(rotation));
	D3DXMatrixScaling(&mat_scale, 1 / scale, 1 / scale, 1);
	D3DXMatrixTranslation(&screen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);

	mat = mat_position * mat_scale * mat_rotation * screen;

	return mat;
}
