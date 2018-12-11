#pragma once

#include "SDLGameObject.h"

class AnimatedGraphics : public SDLGameObject {
public:
	AnimatedGraphics(const LoaderParams* pParams, int animSpeed);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	int m_animSpeed;
};