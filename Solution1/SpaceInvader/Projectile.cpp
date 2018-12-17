#include "Game.h"
#include "Projectile.h"
using namespace std;

Projectile::Projectile(const LoaderParams* pParams) :

	SDLGameObject(pParams) {
	std::cout << "creating a bullet" << std::endl;
}

void Projectile::draw() {
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY()
		, m_width, m_height, TheGame::Instance()->getRenderer());
}

void Projectile::update() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_acceleration.setY(-4);
	SDLGameObject::update();
}

void Projectile::Collide(SDLGameObject* pCollider) {
	pCollider->Collide(this);
	if (TheCollider::Instance()->Collision(this, pCollider)) {
		std::vector<SDLGameObject*>::iterator iter;
		std::vector<SDLGameObject*>::iterator iterEnd = PlayState::Instance()->getGameObjects()->end();
		for (iter = PlayState::Instance()->getGameObjects()->begin(); iter != iterEnd; iter++)
		{
			if (*iter == this)
			{
				PlayState::Instance()->getGameObjects()->erase(iter);
				Player::Instance()->BulletReady();
				break;
			}
		}
	}
}

void Projectile::clean() {

}