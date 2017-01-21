#include "GameWinScreen.h"
#include "ProjectConstants.h"

GameWinScreen::GameWinScreen() {
}

GameWinScreen::~GameWinScreen() {
}

void GameWinScreen::init() {
	//m_image.load(ProjectConstants::IMG_PATH_SCREEN_GAMEWIN);
}

void GameWinScreen::render() {
	ofSetRectMode(OF_RECTMODE_CORNER);

	ofFill();
	ofSetColor(ofColor::white);
	m_image.draw(0, 0);
}
