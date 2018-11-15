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
	bulletActive = int(((SDL_GetTicks() / 10) % 11));
	SDLGameObject::update();
}

void Player::clean() {

}

void Player::Collide(GameObject* pCollider) {

}

void Player::handleInput() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-2);
	}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
	//	m_velocity.setY(-2);
	//}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
	//	m_velocity.setY(2);
	//}
	if (TheInputHandler::Instance()->isKeyPressed(SDL_SCANCODE_SPACE)) {
		if (bulletActive == 0) {
			TheGame::Instance()->getGameObjects()->push_back(new Projectile(new LoaderParams(this->m_position.getX() + 25, this->m_position.getY(), 8, 48, "bullet", "Bullet")));
		}
	}
}