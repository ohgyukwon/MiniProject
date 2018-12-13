#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Collider.h"
#include "PlayState.h"

class Enemy : public SDLGameObject {
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void Collide(SDLGameObject* pCollider);
private:
	void handleInput();
};