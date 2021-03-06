#pragma once

#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "InputHandler.h"

class Collider {
public:
	static Collider* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Collider();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	bool Collision(SDLGameObject* object1, SDLGameObject* object2);
private:
	Collider();
	int rc1_left, rc1_right, rc1_top, rc1_bottom;
	int rc2_left, rc2_right, rc2_top, rc2_bottom;
	static Collider* s_pInstance;
};

typedef Collider TheCollider;