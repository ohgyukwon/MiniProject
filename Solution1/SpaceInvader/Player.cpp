#include "Player.h"

Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams) {
}

void Player::draw() {
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY()
		, m_width, m_height, TheGame::Instance()->getRenderer());
}

void Player::update() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	SDLGameObject::update();
}

void Player::clean() {

}

void Player::handleInput() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyPressed(SDL_SCANCODE_SPACE)) {
		PlayState::Instance()->getGameObjects()->push_back(new Projectile(new LoaderParams(this->m_position.getX() + 30, this->m_position.getY() - 10, 2, 18, "bullet", "BULLET")));
	}
}

//void Player::Collide(SDLGameObject* pCollider) {
//	if (TheCollider::Instance()->Collision(this, pCollider)) {
//		std::vector<SDLGameObject*>::iterator iter;
//		std::vector<SDLGameObject*>::iterator iterEnd = PlayState::Instance()->getEnemyObjects()->end();
//		for (iter = PlayState::Instance()->getEnemyObjects()->begin(); iter != iterEnd; iter++)
//		{
//			if (*iter == this)
//			{
//				PlayState::Instance()->getEnemyObjects()->erase(iter);
//				break;
//			}
//		}
//	}
//}