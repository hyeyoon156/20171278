#include <iostream>
#include "Fire.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "InputHandler.h"

//void Enemy::update()
//{
//	GameObject::update();
//	m_y += 1;
//	//m_x += 1;
//	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
//}

Fire::Fire(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Fire::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Fire::update()
{
	m_position.setX(m_position.getX()+3);
	//m_position.setY(m_position.getY());

	m_currentFrame = int(((SDL_GetTicks() / 100)%1));

	handleInput();
	//GameObject::update();
}

void Fire::clean()
{
}

void Fire::handleInput()
{

	//if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	//{
	//	m_velocity.setX(1);
	//	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	//	m_velocity = (*vec - m_position) / 100;
		SDLGameObject::update();
	//}
}
