#pragma once

#include "GameState.h"
#include "MenuState.h"
#include "AnimatedGraphics.h"

class GameObject;

class WinState :public GameState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_winID; }
	static WinState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new WinState();
		}
		return s_pInstance;
	}
private:
	static void s_winToExit();
	static void s_restartPlay();
	static const std::string s_winID;
	static WinState* s_pInstance;
};