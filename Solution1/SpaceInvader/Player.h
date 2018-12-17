#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"
#include "Projectile.h"

class Player :public SDLGameObject {
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void BulletReady();
	void BulletNotReady();
	static Player* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Player(new LoaderParams(360, 400, 64, 64, "player"));
		}
		return s_pInstance;
	}
private:
	void handleInput();
	bool bulletReady;
	static Player* s_pInstance;
};