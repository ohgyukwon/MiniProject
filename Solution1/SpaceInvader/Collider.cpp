#include "Collider.h"

Collider* Collider::s_pInstance = 0;

Collider::Collider() {

}

void Collider::update() {

}

void Collider::clean() {

}

bool Collider::Collision(GameObject* object1, GameObject* object2) {
	//if (object1 == object2) return false;
	//if ((object1->getTag() == "Player" && object2->getTag() == "Bullet") ||
		//(object1->getTag() == "Bullet" && object2->getTag() == "Player"))
		//return false;

	rc1_left = object1->getPositionX();
	rc1_right = object1->getPositionX() + object1->getWidth();
	rc1_top = object1->getPositionY();
	rc1_bottom = object1->getPositionY() + object1->getHeight();

	rc2_left = object2->getPositionX();
	rc2_right = object2->getPositionX() + object2->getWidth();
	rc2_top = object2->getPositionY();
	rc2_bottom = object2->getPositionY() + object2->getHeight();

	if (rc1_left < rc2_right &&
		rc1_top < rc2_bottom &&
		rc1_right > rc2_left &&
		rc1_bottom > rc2_top)
		return true;
	else
		return false;
	return false;
}