#pragma once

#include "ofMain.h"
#include "../ProjectConstants.h"

class TitleScreen
{
public:
	TitleScreen();
	~TitleScreen();

	void init();
	void render();

private:
	ofImage	      m_image;

};