#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"

class Enemy : public SDLGameObject {
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void Collide(GameObject* pCollider);
	virtual int getPositionX() { return this->m_position.getX(); }
	virtual int getPositionY() { return this->m_position.getY(); }
	virtual int getWidth() { return this->m_width; }
	virtual int getHeight() { return this->m_height; }
	virtual std::string getTag() { return this->m_tag; };
private:
	void handleInput();
};