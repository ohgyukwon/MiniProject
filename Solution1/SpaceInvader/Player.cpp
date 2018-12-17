#include "Player.h"

Player* Player::s_pInstance = 0;

Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams) {
	bulletReady = true;
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
	if (TheInputHandler::Instance()->isKeyPressed(SDL_SCANCODE_SPACE) && bulletReady) {
		PlayState::Instance()->getGameObjects()->push_back(new Projectile(new LoaderParams(this->m_position.getX() + 30, this->m_position.getY() - 15, 2, 18, "bullet")));
		BulletNotReady();
	}
}

void Player::BulletReady() {
	this->bulletReady = true;
}

void Player::BulletNotReady() {
	this->bulletReady = false;
}