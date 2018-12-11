#include "Collider.h"

Collider* Collider::s_pInstance = 0;

Collider::Collider() {

}

void Collider::update() {

}

void Collider::clean() {

}

bool Collider::Collision(SDLGameObject* object1, SDLGameObject* object2) {
	//if (object1 == object2) return false;
	//if ((object1->getTag() == "Player" && object2->getTag() == "Bullet") ||
		//(object1->getTag() == "Bullet" && object2->getTag() == "Player"))
		//return false;

	rc1_left = object1->getPosition().getX();
	rc1_right = object1->getPosition().getX() + object1->getWidth();
	rc1_top = object1->getPosition().getY();
	rc1_bottom = object1->getPosition().getY() + object1->getHeight();

	rc2_left = object2->getPosition().getX();
	rc2_right = object2->getPosition().getX() + object2->getWidth();
	rc2_top = object2->getPosition().getY();
	rc2_bottom = object2->getPosition().getY() + object2->getHeight();

	if (rc1_left < rc2_right &&
		rc1_top < rc2_bottom &&
		rc1_right > rc2_left &&
		rc1_bottom > rc2_top)
		return true;
	else
		return false;
	return false;
}