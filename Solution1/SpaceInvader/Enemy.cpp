#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) :

	SDLGameObject(pParams) {

}

void Enemy::draw() {
	SDLGameObject::draw();
}

void Enemy::update() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = int(((SDL_GetTicks() / 300) % 2));
	SDLGameObject::update();
}

void Enemy::clean() {

}

void Enemy::Collide(GameObject* pCollider) {
	if (TheCollider::Instance()->Collision(this, pCollider) && pCollider->getTag() == "Bullet") {
		//m_textureID = "wall_broken";
	}
}

void Enemy::handleInput() {
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}