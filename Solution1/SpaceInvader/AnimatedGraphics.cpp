#include "AnimatedGraphics.h"

AnimatedGraphics::AnimatedGraphics(const LoaderParams* pParams, int animSpeed) : SDLGameObject(pParams), m_animSpeed(animSpeed) {
	m_numFrames = 2;
}

void AnimatedGraphics::draw() {
	SDLGameObject::draw();
}

void AnimatedGraphics::update() {
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphics::clean() {
	SDLGameObject::clean();
}