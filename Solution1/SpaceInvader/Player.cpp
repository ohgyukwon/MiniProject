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
		PlayState::Instance()->getGameObjects()->push_back(new Projectile(new LoaderParams(this->m_position.getX() + 28, this->m_position.getY() - 20, 4, 24, "bullet", "BULLET")));
	}
}