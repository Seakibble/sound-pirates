#pragma once

#include "ofMain.h"
#include "ProjectConstants.h"

#include "app-screens/TitleScreen.h"
#include "app-screens/GameOverScreen.h"
#include "app-screens/GameWinScreen.h"

#include "game/Game.h"

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
