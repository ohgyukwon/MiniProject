#pragma once

#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "Collider.h"

class Game {
private:
	Game() {}
	static Game* s_pInstance;
	std::map<std::string, SDL_Texture*> m_textureMap;
	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*>::iterator iter1, iter2;
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void render();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() { return m_pRenderer; }
	void update();
	void clean();
	void quit();
	std::vector<GameObject*> *getGameObjects() { return &m_gameObjects; }

	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
};

typedef Game TheGame;