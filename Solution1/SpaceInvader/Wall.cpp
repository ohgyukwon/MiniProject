#include "Wall.h"

Wall::Wall(const LoaderParams* pParams) :
	SDLGameObject(pParams) {
	m_velocity.setX(0);
	m_velocity.setY(0);
}

void Wall::draw() {
	TextureManager::Instance()->draw(m_textureID,
		(Uint32)m_position.getX(), (Uint32)m_position.getY()
		, m_width, m_height, TheGame::Instance()->getRenderer());
}

void Wall::update() {
	
}

void Wall::clean() {
	SDLGameObject::clean();
}

void Wall::Collide(SDLGameObject* pCollider) {
	
}