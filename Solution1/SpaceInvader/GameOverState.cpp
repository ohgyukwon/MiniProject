#include "GameOverState.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";
GameOverState* GameOverState::s_pInstance = 0;

void GameOverState::s_gameOverToMain() {
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void GameOverState::s_restartPlay() {
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}

void GameOverState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void GameOverState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool GameOverState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/gameover.png", "gameoverText", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/main.png", "mainButton", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/re.png", "restartButton", TheGame::Instance()->getRenderer())) return false;

	GameObject* gameOverText = new AnimatedGraphics(new LoaderParams(300, 100, 190, 30, "gameoverText", "TEXT"), 2);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 400, 400, 100, "mainButton", "BUTTON"), s_gameOverToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 200, 400, 100, "restartButton", "BUTTON"), s_restartPlay);
	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering GameOverState\n";
	return true;
}

bool GameOverState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("gameoverText");
	TheTextureManager::Instance()->clearFromTextureMap("mainButton");
	TheTextureManager::Instance()->clearFromTextureMap("restartButton");
	TheInputHandler::Instance()->reset();
	std::cout << "exiting GameOverState\n";
	return true;
}