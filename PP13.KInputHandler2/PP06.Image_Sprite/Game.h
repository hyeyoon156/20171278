#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#include <SDL.h>
#include <vector>
#include <iostream>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Fire.h"
#include "GameObject.h"


class Game
{
	//SDL_Texture* m_pTexture; // the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle; // 원본 사각형 
	//SDL_Rect m_destinationRectangle; // 대상 사각형
	//SDL_Rect m_destinationRectangle2; // 대상 사각형
	int m_currentFrame;
	TextureManager m_textureManager;
	/*GameObject m_go;
	Player m_player;*/
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

	std::vector<GameObject*> m_gameObjects;

	Game() {};
	// create the s_pInstance member variable
	static Game* s_pInstance;
	// create the typedef

public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() { std::cout << "quit" << std::endl; m_bRunning = false; };
	bool running() { return m_bRunning; }

private:

	~Game() {}

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	//SDL_Texture* m_pTexture; //
	//SDL_Rect m_sourceRectangle; //
	//SDL_Rect m_destinationRectangle; //
};
	typedef Game TheGame;
#endif