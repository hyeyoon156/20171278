#pragma once
#include <SDL.h>
#include <vector>
#include "TextureManager.h"
//#include "Player.h"
//#include "Enemy.h"
#include "GameObject.h"


class Game
{
	//SDL_Texture* m_pTexture; // the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle; // ���� �簢�� 
	//SDL_Rect m_destinationRectangle; // ��� �簢��
	//SDL_Rect m_destinationRectangle2; // ��� �簢��
	int m_currentFrame;
	TextureManager m_textureManager;
	/*GameObject m_go;
	Player m_player;*/
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	std::vector<GameObject*> m_gameObjects;

public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	//SDL_Texture* m_pTexture; //
	//SDL_Rect m_sourceRectangle; //
	//SDL_Rect m_destinationRectangle; //
};

