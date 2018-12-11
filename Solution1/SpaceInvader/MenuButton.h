#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

enum button_state {
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

class MenuButton : public SDLGameObject {
private:
	bool m_bReleased;
public:
	MenuButton(const LoaderParams* pParams, void(*callback)());
	virtual void draw();
	virtual void update();
	virtual void clean();
	void(*m_callback)();
};