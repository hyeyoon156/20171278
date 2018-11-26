#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Enemy : public SDLGameObject
{
public:
	//void load(int x, int y, int width, int height,
	//	std::string textureID);
	Enemy(const LoaderParams* pParams);
	/*void draw(SDL_Renderer* pRenderer);*/
	virtual void draw();
	virtual void update();
	virtual void clean();
	void handleInput();
};