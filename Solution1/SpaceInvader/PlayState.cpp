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
	for (int i = 0; i < m_enemyObjects.size(); i++) {
		m_enemyObjects[i]->update();
	}
	for (int j = 0; j < m_enemyObjects.size(); j++) {
		// 플레이어와 적
		if (TheCollider::Instance()->Collision(dynamic_cast<SDLGameObject*>(m_enemyObjects[j]), dynamic_cast<SDLGameObject*>(m_gameObjects[0]))) {
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
		// 총알과 적
		for (int i = 1; i < m_gameObjects.size(); i++) {
			if (TheCollider::Instance()->Collision(dynamic_cast<SDLGameObject*>(m_enemyObjects[j]), dynamic_cast<SDLGameObject*>(m_gameObjects[i]))) {
				m_gameObjects[i]->Collide(m_enemyObjects[j]);
			}
		}
	}
	if (count >= 21) {
		TheGame::Instance()->getStateMachine()->changeState(WinState::Instance());
	}
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	for (int i = 0; i < m_enemyObjects.size(); i++) {
		m_enemyObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/player.png", "player", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/enemy_1.png", "enemy_1", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/enemy_2.png", "enemy_2", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/enemy_3.png", "enemy_3", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/wall.png", "wall", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/bullet.png", "bullet", TheGame::Instance()->getRenderer())) return false;

	count = 0;
	m_gameObjects.push_back(Player::Instance());
	Player::Instance()->BulletReady();

	// 첫째 줄
	SDLGameObject* enemy1 = new Enemy(new LoaderParams(60, 50, 64, 64, "enemy_1")); m_enemyObjects.push_back(enemy1);
	SDLGameObject* enemy2 = new Enemy(new LoaderParams(160, 50, 64, 64, "enemy_3")); m_enemyObjects.push_back(enemy2);
	SDLGameObject* enemy3 = new Enemy(new LoaderParams(260, 50, 64, 64, "enemy_2")); m_enemyObjects.push_back(enemy3);
	SDLGameObject* enemy4 = new Enemy(new LoaderParams(360, 50, 64, 64, "enemy_1")); m_enemyObjects.push_back(enemy4);
	SDLGameObject* enemy5 = new Enemy(new LoaderParams(460, 50, 64, 64, "enemy_2")); m_enemyObjects.push_back(enemy5);
	SDLGameObject* enemy6 = new Enemy(new LoaderParams(560, 50, 64, 64, "enemy_3")); m_enemyObjects.push_back(enemy6);
	SDLGameObject* enemy7 = new Enemy(new LoaderParams(660, 50, 64, 64, "enemy_1")); m_enemyObjects.push_back(enemy7);
	// 둘째 줄
	SDLGameObject* enemy8 = new Enemy(new LoaderParams(60, 150, 64, 64, "enemy_3")); m_enemyObjects.push_back(enemy8);
	SDLGameObject* enemy9 = new Enemy(new LoaderParams(160, 150, 64, 64, "enemy_2")); m_enemyObjects.push_back(enemy9);
	SDLGameObject* enemy10 = new Enemy(new LoaderParams(260, 150, 64, 64, "enemy_1")); m_enemyObjects.push_back(enemy10);
	SDLGameObject* enemy11 = new Enemy(new LoaderParams(360, 150, 64, 64, "enemy_1")); m_enemyObjects.push_back(enemy11);
	SDLGameObject* enemy12 = new Enemy(new LoaderParams(460, 150, 64, 64, "enemy_1")); m_enemyObjects.push_back(enemy12);
	SDLGameObject* enemy13 = new Enemy(new LoaderParams(560, 150, 64, 64, "enemy_2")); m_enemyObjects.push_back(enemy13);
	SDLGameObject* enemy14 = new Enemy(new LoaderParams(660, 150, 64, 64, "enemy_3")); m_enemyObjects.push_back(enemy14);
	// 셋째 줄
	SDLGameObject* enemy15 = new Enemy(new LoaderParams(60, 250, 64, 64, "enemy_2")); m_enemyObjects.push_back(enemy15);
	SDLGameObject* enemy16 = new Enemy(new LoaderParams(160, 250, 64, 64, "enemy_2")); m_enemyObjects.push_back(enemy16);
	SDLGameObject* enemy17 = new Enemy(new LoaderParams(260, 250, 64, 64, "enemy_1")); m_enemyObjects.push_back(enemy17);
	SDLGameObject* enemy18 = new Enemy(new LoaderParams(360, 250, 64, 64, "enemy_3")); m_enemyObjects.push_back(enemy18);
	SDLGameObject* enemy19 = new Enemy(new LoaderParams(460, 250, 64, 64, "enemy_1")); m_enemyObjects.push_back(enemy19);
	SDLGameObject* enemy20 = new Enemy(new LoaderParams(560, 250, 64, 64, "enemy_2")); m_enemyObjects.push_back(enemy20);
	SDLGameObject* enemy21 = new Enemy(new LoaderParams(660, 250, 64, 64, "enemy_2")); m_enemyObjects.push_back(enemy21);
	// 게임 외벽
	SDLGameObject* wall = new Wall(new LoaderParams(0, 0, 800, 10, "wall")); m_enemyObjects.push_back(wall);

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
		m_enemyObjects[i]->clean();
	}
	m_gameObjects.clear();
	m_enemyObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("player");
	TheTextureManager::Instance()->clearFromTextureMap("enemy_1");
	TheTextureManager::Instance()->clearFromTextureMap("enemy_2");
	TheTextureManager::Instance()->clearFromTextureMap("enemy_3");

	std::cout << "exiting PlayState\n";
	return true;
}

void PlayState::increaseCount() {
	count++;
}