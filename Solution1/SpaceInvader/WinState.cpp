#include "WinState.h"

const std::string WinState::s_winID = "WIN";
WinState* WinState::s_pInstance = 0;

void WinState::s_winToExit() {
	std::cout << "Exit button clicked\n";
	TheGame::Instance()->quit();
}

void WinState::s_restartPlay() {
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}

void WinState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void WinState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool WinState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/winText.png", "winText", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/exit.png", "exitButton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/re.png", "restartButton", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* winText = new AnimatedGraphics(new LoaderParams(300, 100, 190, 30, "winText"), 2);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 400, 400, 100, "exitButton"), s_winToExit);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 200, 400, 100, "restartButton"), s_restartPlay);
	m_gameObjects.push_back(winText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering WinState\n";
	return true;
}

bool WinState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("winText");
	TheTextureManager::Instance()->clearFromTextureMap("exitButton");
	TheTextureManager::Instance()->clearFromTextureMap("restartButton");
	TheInputHandler::Instance()->reset();
	std::cout << "exiting GameOverState\n";
	return true;
}