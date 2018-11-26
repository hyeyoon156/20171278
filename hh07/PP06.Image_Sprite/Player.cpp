#include <iostream>
#include "Player.h"
#include "Fire.h"
//#include "Game.h"
#include "SDLGameObject.h"
#include "InputHandler.h"

std::vector<GameObject*> m_gameObjects;
//SDL_Renderer* m_pRenderer;
int delay = 10;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
	//SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(/*m_pRenderer*/);
	}
	//SDL_RenderPresent(m_pRenderer);
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->getMouseButtonState(RIGHT))
	{
		if (!delay--)
		{
			m_gameObjects.push_back(new Fire(new LoaderParams(210, 100, 80, 80, "bullet")));
			delay = 30;
		}
	}
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	SDLGameObject::update();
}

//void Player::update()
//{
//	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
//	m_acceleration.setX(1);
//	SDLGameObject::update();
//}

void Player::clean()
{
}

//void Player::load(int x, int y, int width, int height,
//	std::string textureID)
//{
//	GameObject::load(x, y, width, height, textureID);
//	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
//}
//
//void Player::draw(SDL_Renderer* pRenderer)
//{
//	GameObject::draw(pRenderer);
//	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
//}
//
//void Player::update()
//{
//	m_x -= 1;
//}