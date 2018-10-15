#include <iostream>
#include "Game.h"
#include <SDL_image.h>
#include "SDL.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true; //

		//SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
		//SDL_Surface* pTempSurface = IMG_Load("assets/animate.png");
		SDL_Surface* pTempSurface = IMG_Load("assets/New_Piskel.png");

		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
			pTempSurface);
		SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = m_sourceRectangle2.w = 128;
		m_sourceRectangle.h = m_sourceRectangle2.h = 128;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;

		//m_destinationRectangle2.x = m_sourceRectangle2.x = 100;
		//m_destinationRectangle2.y = m_sourceRectangle2.y = 0;
		//m_destinationRectangle2.w = m_sourceRectangle2.w;
		//m_destinationRectangle2.h = m_sourceRectangle2.h;

		SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 255, 0);

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

	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	//SDL_RenderClear(m_pRenderer);
	//SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle2, &m_destinationRectangle2);
	SDL_RenderPresent(m_pRenderer);

}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::update()
{
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	//m_sourceRectangle2.x = 128 * int(((SDL_GetTicks() / 50) % 6));
	//m_destinationRectangle2.x += 0.5;
	//if (m_destinationRectangle2.x >= 300.0f)
	//{
	//	m_destinationRectangle2.x = 100.0f;
	//}
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