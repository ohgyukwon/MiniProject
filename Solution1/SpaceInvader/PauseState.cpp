#include "PauseState.h"

const std::string PauseState::s_pauseID = "PAUSE";
PauseState* PauseState::s_pInstance = 0;

void PauseState::s_pauseToMain() {
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay() {
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PauseState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/resume.png", "resumeButton", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/main.png", "mainButton", TheGame::Instance()->getRenderer())) return false;

	GameObject* button1 = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumeButton", "BUTTON"), s_resumePlay);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 100, 400, 100, "mainButton", "BUTTON"), s_pauseToMain);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("resumeButton");
	TheTextureManager::Instance()->clearFromTextureMap("mainButton");
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}