#include "ofApp.h"
#include "ProjectConstants.h"
//--------------------------------------------------------------
void ofApp::setup(){

	ofSetWindowShape(
		ProjectConstants::PROJ_WINDOW_RES_X,
		ProjectConstants::PROJ_WINDOW_RES_Y);

	ofSetFrameRate(ProjectConstants::PROJ_DESIRED_FRAMERATE);

	// Initialize our 3 screens
	m_titleScreen.init();
	m_gameOverScreen.init();
	m_winScreen.init();

	// Initialize the game
	m_game.init(); 

	// start out on the title screen
	m_appState = AppState::ScreenTitle;
}

void ofApp::beginGame() {
	m_game.begin();
	m_appState = AppState::GamePlaying;
}

//--------------------------------------------------------------
void ofApp::update(){
	// where are we? title screen, game, game over screen, or game win screen?
	// switch() is an alternative to an if statement

	switch (m_appState)
	{
	case AppState::ScreenTitle:
		if (ofGetKeyPressed('x'))
		{
			beginGame();
		}
		break;

	case AppState::GamePlaying:
		m_game.update();

		if (m_game.getGameState() == Game::GameState::GameOver)
		{
			m_appState = AppState::ScreenGameOver;
		}
		else if (m_game.getGameState() == Game::GameState::GameWin)
		{
			m_appState = AppState::ScreenGameWin;
		}
		break;

	case AppState::ScreenGameOver:
		if (ofGetKeyPressed('x'))
		{
			beginGame();
		}
		break;

	case AppState::ScreenGameWin:
		if (ofGetKeyPressed('x'))
		{
			beginGame();
		}
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(ofFloatColor(0.0f, 0.0f, 0.0f, 1.0f));

	switch (m_appState)
	{
	case AppState::ScreenTitle:
		m_titleScreen.render();
		break;

	case AppState::GamePlaying:
		m_game.render();
		break;

	case AppState::ScreenGameOver:
		m_game.render();
		m_gameOverScreen.render();
		break;

	case AppState::ScreenGameWin:
		m_game.render();
		m_winScreen.render();
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
