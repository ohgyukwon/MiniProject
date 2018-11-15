#pragma once

#include "Vector2D.h"
#include "GameObject.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void Collide(GameObject* pCollider);
	virtual int getPositionX() { return this->m_position.getX(); }
	virtual int getPositionY() { return this->m_position.getY(); }
	virtual int getWidth() { return this->m_width; }
	virtual int getHeight() { return this->m_height; }
	virtual std::string getTag() { return this->m_tag; };
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
	std::string m_tag;
};