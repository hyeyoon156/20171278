#include <iostream>
#include "Player.h"
#include "SDLGameObject.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Player::clean()
{
}

//void Player::load(int x, int y, int width, int height,
//	std::string textureID)
//{
//	GameObject::load(x, y, width, height, textureID);
//	// �� �ڵ尡 �ǹ̰� ������? ���ڵ尡 �����ٸ�, �ڵ����� �θ� ȣ��?? 
//}
//
//void Player::draw(SDL_Renderer* pRenderer)
//{
//	GameObject::draw(pRenderer);
//	// �� �ڵ尡 �ǹ̰� ������? ���ڵ尡 �����ٸ�, �ڵ����� �θ� ȣ��?? 
//}
//
//void Player::update()
//{
//	m_x -= 1;
//}