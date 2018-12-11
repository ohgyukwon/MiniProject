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
	if (!TheTextureManager::Instance()->load("Assets/gameover.png", "gameoverText", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/main.png", "mainButton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/restart.png", "restartButton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/player.png", "playerSprite", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/background.png", "background", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* gameOverText = new AnimatedGraphics(new LoaderParams(500, 200, 190, 30, "gameoverText", "menuButton"), 2);
	GameObject* button1 = new MenuButton(new LoaderParams(100, 300, 400, 100, "mainButton", "menuButton"), s_gameOverToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 100, 200, 80, "restartButton", "menuButton"), s_restartPlay);
	GameObject* playerSprite = new AnimatedGraphics(new LoaderParams(100, 100, 30, 30, "playerSprite", "menuButton"), 2);
	GameObject* background = new AnimatedGraphics(new LoaderParams(0, 0, 1200, 800, "background", "menuButton"), 2);
	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(playerSprite);
	m_gameObjects.push_back(background);
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
	TheTextureManager::Instance()->clearFromTextureMap("playerSprite");
	TheTextureManager::Instance()->clearFromTextureMap("background");
	TheInputHandler::Instance()->reset();
	std::cout << "exiting GameOverState\n";
	return true;
}