#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(MenuState::Instance());
	}
	else {
		m_bRunning = false;
		return false;
	}
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);	// ¹è°æ »ö±ò
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	//for (int i = 0; i < m_gameObjects.size() - 1; i++) {
	//	for (int j = i + 1; j < m_gameObjects.size(); j++) {
	//		if (TheCollider::Instance()->Collision(m_gameObjects[i], m_gameObjects[j]))
	//			m_gameObjects[i]->Collide(m_gameObjects[j]);
	//		m_gameObjects[j]->Collide(m_gameObjects[i]);
	//	}
	//}
}

void Game::clean() {
	TheInputHandler::Instance()->clean();
	std::cout << "cleanning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
	TheCollider::Instance()->update();
}

void Game::quit() {
	m_bRunning = false;
}