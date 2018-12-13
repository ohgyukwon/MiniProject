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
	// 적이 둘 이상일 때, 총알과 적 둘 다 제거
	// 태그 비교하여 적절하지 않은 경우에는 return?
	// NULL인 경우에도 return?
	for (int i = 6; i < m_gameObjects.size(); i++) {
		if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[1]), dynamic_cast<SDLGameObject*>(m_gameObjects[i]))) {
			m_gameObjects[1]->Collide(m_gameObjects[i]);
		}
	}
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/player.png", "player", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/enemy_1.png", "enemy_1", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/enemy_2.png", "enemy_2", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/enemy_3.png", "enemy_3", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/bullet.png", "bullet", TheGame::Instance()->getRenderer())) return false;

	SDLGameObject* player = new Player(new LoaderParams(360, 500, 64, 64, "player", "PLAYER")); m_gameObjects.push_back(player);
	SDLGameObject* enemy1 = new Enemy(new LoaderParams(360, 100, 64, 64, "enemy_1", "ENEMY")); m_gameObjects.push_back(enemy1);
	SDLGameObject* enemy2 = new Enemy(new LoaderParams(260, 100, 64, 64, "enemy_2", "ENEMY")); m_gameObjects.push_back(enemy2);
	SDLGameObject* enemy3 = new Enemy(new LoaderParams(460, 100, 64, 64, "enemy_2", "ENEMY")); m_gameObjects.push_back(enemy3);
	SDLGameObject* enemy4 = new Enemy(new LoaderParams(560, 100, 64, 64, "enemy_3", "ENEMY")); m_gameObjects.push_back(enemy4);
	SDLGameObject* enemy5 = new Enemy(new LoaderParams(160, 100, 64, 64, "enemy_3", "ENEMY")); m_gameObjects.push_back(enemy5);
	
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("player");
	TheTextureManager::Instance()->clearFromTextureMap("enemy_1");
	TheTextureManager::Instance()->clearFromTextureMap("enemy_2");
	TheTextureManager::Instance()->clearFromTextureMap("enemy_3");

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
