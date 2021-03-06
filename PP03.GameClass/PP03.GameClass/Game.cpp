#include <iostream>
#include "Game.h"
//#include "SDL.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen /*SDL_WINDOW_SHOWN*/);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true; //
		//SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp"); //
		//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface); //
		//SDL_FreeSurface(pTempSurface); //
		//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h); //
	}
	else
	{
		return false;
	}
	return true;
}

void Game::render()
{
	//m_sourceRectangle.x= 40;
	//m_sourceRectangle.y = 40;
	//m_destinationRectangle.x = m_sourceRectangle.x;
	//m_destinationRectangle.y = m_sourceRectangle.y;
	//m_sourceRectangle.w = 50; // 이미지 / m_destinationRectangle.w = 사각형
	//m_sourceRectangle.h = 50;
	//m_destinationRectangle.w = m_sourceRectangle.w; //d = s = 50
	//m_destinationRectangle.h = m_sourceRectangle.h;

	SDL_RenderClear(m_pRenderer);
	//SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}