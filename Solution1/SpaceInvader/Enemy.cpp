#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) :
	SDLGameObject(pParams) {
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_numFrames = 2;
	goDistance = 50;
	originalX = m_position.getX();
}

void Enemy::draw() {
	SDLGameObject::draw();
}

void Enemy::update() {
	m_currentFrame = int(((SDL_GetTicks() / 300) % m_numFrames));

	if (int(((SDL_GetTicks() / 1000) % 3)) == 0) {
		if(m_position.getX() <= originalX + goDistance)
			m_position.setX(m_position.getX() + 0.5);
		else if (m_position.getX() >= originalX) {
			m_position.setX(m_position.getX() - 70.0);
			m_position.setY(m_position.getY() + 30);
		}
	}
	SDLGameObject::update();
}

void Enemy::clean() {
	SDLGameObject::clean();
}

void Enemy::handleInput() {

}

void Enemy::Collide(SDLGameObject* pCollider) {
	if (TheCollider::Instance()->Collision(this, pCollider)) {
		std::vector<SDLGameObject*>::iterator iter;
		std::vector<SDLGameObject*>::iterator iterEnd = PlayState::Instance()->getEnemyObjects()->end();
		for (iter = PlayState::Instance()->getEnemyObjects()->begin(); iter != iterEnd; iter++)
		{
			if (*iter == this)
			{
				PlayState::Instance()->getEnemyObjects()->erase(iter);
				break;
			}
		}
	}
}