#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (window != 0) {
			screen = SDL_CreateRenderer(window, -1, 0);
		}

		isRunning = true;
	}
	else {
		isRunning = false;
		return false;
	}

	SDL_Surface* image = IMG_Load("Assets/animate-alpha.png");
	texture = SDL_CreateTextureFromSurface(screen, image);
	SDL_FreeSurface(image);

	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	SDL_SetRenderDrawColor(screen, 255, 0, 255, 255);
	return true;
}

void Game::MoveImage() {
	m_destinationRectangle.x += x;
	m_destinationRectangle.y += y;
}

void Game::render() {
	SDL_RenderClear(screen);
	SDL_RenderCopy(screen, texture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(screen);
}

void Game::update() {
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	MoveImage();
}

void Game::clean() {
	std::cout << "cleanning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(screen);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:	
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				x-=1;
				break;
			case SDLK_RIGHT:
				x+=1;
				break;
			case SDLK_UP:
				y-=1;
				break;
			case SDLK_DOWN:
				y+=1;
				break;
			}
			break;
		default:
			break;
		}
	}

	SDL_Delay(1);
}