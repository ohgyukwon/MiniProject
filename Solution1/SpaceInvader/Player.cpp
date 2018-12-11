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

void Player::Collide(SDLGameObject* pCollider) {

}

void Player::handleInput() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && bulletstate == READY) {
		TheGame::Instance()->getGameObjects()->push_back(new Projectile(new LoaderParams(this->m_position.getX() + 28, this->m_position.getY(), 4, 24, "bullet", "Bullet")));
		bulletstate = FIRED;
		// 총알 없어지면 다시 READY
		// 빗나간 총알은 게임 화면 밖에 안보이는 벽 생성해서 충돌 처리
	}
}