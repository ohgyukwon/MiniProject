#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Game.h"
#include "Projectile.h"

enum bulletState {
	READY,
	FIRED 
};

class Player :public SDLGameObject {
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void Collide(SDLGameObject* pCollider);
private:
	int bulletActive = 1;
	void handleInput();
	std::vector<GameObject*> m_bullets;
	bulletState bulletstate = READY;
};