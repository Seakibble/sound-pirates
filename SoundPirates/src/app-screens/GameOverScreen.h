#pragma once

#include "ofMain.h"
#include "../ProjectConstants.h"

class GameOverScreen
{
public:
    GameOverScreen();
    ~GameOverScreen();

    void init();
    void render();

private:
    ofImage     m_image;
};
