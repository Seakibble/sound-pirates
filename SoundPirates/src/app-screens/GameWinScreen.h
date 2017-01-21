#pragma once

#include "ofMain.h"
#include "../ProjectConstants.h"

class GameWinScreen
{
public:
	GameWinScreen();
	~GameWinScreen();

	void init();
	void render();

private:
	ofImage	      m_image;
};
