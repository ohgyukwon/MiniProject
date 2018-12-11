#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;


void PlayState::update() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	for (int i = 1; i < m_gameObjects.size(); i++) {
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/player.png", "animate", TheGame::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("Assets/Horizontal (2).png", "enemy1", TheGame::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("Assets/bullet2.png", "bullet", TheGame::Instance()->getRenderer())) {
		return false;
	}

	m_gameObjects.push_back(new Player(new LoaderParams(250, 500, 64, 64, "animate", "Player")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(100, 100, 64, 64, "enemy1", "Enemy")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(200, 100, 64, 64, "enemy1", "Enemy")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 100, 64, 64, "enemy1", "Enemy")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(400, 100, 64, 64, "enemy1", "Enemy")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(500, 100, 64, 64, "enemy1", "Enemy")));
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("animated");
	TheTextureManager::Instance()->clearFromTextureMap("enemy1");
	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;

}
