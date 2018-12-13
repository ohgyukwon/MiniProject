#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) :
	SDLGameObject(pParams) {
	m_velocity.setY(2);
	m_velocity.setX(0.001);
	m_numFrames = 2;
}

void Enemy::draw() {
	SDLGameObject::draw();
}

void Enemy::update() {
	m_currentFrame = int(((SDL_GetTicks() / 300) % m_numFrames));

	m_velocity.setX(0);
	m_velocity.setY(0);
	SDLGameObject::update();
}

void Enemy::clean() {
	SDLGameObject::clean();
}

void Enemy::handleInput() {

}

void Enemy::Collide(SDLGameObject* pCollider) {
	if (TheCollider::Instance()->Collision(this, pCollider)) {	// 충돌처리 함수 중복?
		std::vector<SDLGameObject*>::iterator iter;
		std::vector<SDLGameObject*>::iterator iterEnd = PlayState::Instance()->getGameObjects()->end();
		for (iter = PlayState::Instance()->getGameObjects()->begin(); iter != iterEnd; iter++)
		{
			if (*iter == this)
			{
				PlayState::Instance()->getGameObjects()->erase(iter);
				break;
			}
		}
	}
}