#include "MenuState.h"
#include "AnimatedGraphics.h"
#include "PlayState.h"

const std::string MenuState::s_menuID = "MENU";
MenuState* MenuState::s_pInstance = 0;

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/button.png", "playButton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/exit.png", "exitButton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/player.png", "playerSprite", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/background.png", "background", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playButton", "menuButton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitButton", "menuButton"), s_exitFromMenu);
	GameObject* sprite = new AnimatedGraphics(new LoaderParams(100, 100, 30, 30, "playerSprite", "menuButton"), 2);
	GameObject* background = new AnimatedGraphics(new LoaderParams(0, 0, 1200, 800, "background", "background"), 2);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(sprite);
	m_gameObjects.push_back(background);
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playButton");
	TheTextureManager::Instance()->clearFromTextureMap("exitButton");
	TheTextureManager::Instance()->clearFromTextureMap("playerSprite");
	TheTextureManager::Instance()->clearFromTextureMap("background");
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay() {
	std::cout << "Play button clicked\n";
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}

void MenuState::s_exitFromMenu() {
	std::cout << "Exit button clicked\n";
	TheGame::Instance()->quit();
}