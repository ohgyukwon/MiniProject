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
	bool Collision(GameObject* object1, GameObject* object2);
private:
	Collider();
	~Collider();
	int rc1_left, rc1_right, rc1_top, rc1_bottom;
	int rc2_left, rc2_right, rc2_top, rc2_bottom;
	static Collider* s_pInstance;
	std::vector<GameObject*> v;
	std::vector<GameObject*>::iterator iter1, iter2;
};

typedef Collider TheCollider;