#include "Game.h"
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
	m_acceleration.setY(-8);
	SDLGameObject::update();
}

void Projectile::Collide(SDLGameObject* pCollider) {
	if (TheCollider::Instance()->Collision(this, pCollider) && pCollider->getTag() == "Enemy") {
		std::vector<GameObject*>::iterator iter;
		std::vector<GameObject*>::iterator iterEnd = TheGame::Instance()->getGameObjects()->end();
		for (iter = TheGame::Instance()->getGameObjects()->begin(); iter != iterEnd; iter++)
		{
			if (*iter == this)
			{
				TheGame::Instance()->getGameObjects()->erase(iter);
				break;      
			}
		}
	}
}

void Projectile::clean() {

}