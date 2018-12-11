#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"

class Projectile :public SDLGameObject {
public:
	Projectile(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void Collide(SDLGameObject* pCollider);
private:
};