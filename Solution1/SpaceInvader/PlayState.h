#pragma once

#include "GameState.h"
#include "TextureManager.h"
#include "Game.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Wall.h"
#include "WinState.h"

class GameObject;

class PlayState :public GameState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	static PlayState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void increaseCount();
	std::vector<SDLGameObject*> *getGameObjects() { return &m_gameObjects; }
	std::vector<SDLGameObject*> *getEnemyObjects() { return &m_enemyObjects; }
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
	std::vector<SDLGameObject*> m_gameObjects;
	std::vector<SDLGameObject*> m_enemyObjects;
	int count;
};