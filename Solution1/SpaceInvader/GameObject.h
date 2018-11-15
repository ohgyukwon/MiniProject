#pragma once

#include "LoaderParams.h"

class GameObject {
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual void Collide(GameObject* pCollider) = 0;
	virtual int getPositionX() = 0;
	virtual int getPositionY() = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual std::string getTag() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};