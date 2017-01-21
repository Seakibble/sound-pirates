#pragma once

#include "ofMain.h"
#include "AllHeaders.h"

#include "TitleScreen.h"
#include "GameOverScreen.h"
#include "GameWinScreen.h"

class ofApp : public ofBaseApp{

	enum AppState
	{
		Uninitialized,
		ScreenTitle,
		GamePlaying,
		ScreenGameOver,
		ScreenGameWin
	};

	public:
		void setup();
		void beginGame();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);

		AppState              m_appState;
		Game                  m_game;
		
		TitleScreen           m_titleScreen;
		GameOverScreen        m_gameOverScreen;
		GameWinScreen         m_winScreen;
};
