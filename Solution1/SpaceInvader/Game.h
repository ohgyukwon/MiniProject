#pragma once

#include <iostream>
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_keycode.h>

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return isRunning; }
	void MoveImage();
private:
	int x = 0, y = 0;
	SDL_Window * window;
	SDL_Renderer* screen;
	SDL_Texture* texture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	bool isRunning;
};