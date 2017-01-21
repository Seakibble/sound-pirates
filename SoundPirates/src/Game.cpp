#include "AllHeaders.h"

Game::Game()
	: m_state(GameState::NotInitialized)
{
}

Game::~Game() {
}

void Game::init() {
	// game can be in one of five states:
	// NotInitialized, Ready, GamePlaying, GameWin, GameOver
	m_state = GameState::Ready;
	m_bgImage.load(ProjectConstants::IMG_PATH_SCREEN_BACKGROUND);

	m_player.loadImage(ProjectConstants::IMG_PATH_PLAYER);
	m_bullet.init();
}

void Game::update() {
	// Are we playing? then update our objects
	if (m_state == GameState::Playing)
	{
		updateShip();
		updateBullet();
	}
}

void Game::render() {
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofPushMatrix();
		//ofTranslate(m_position);
		m_bgImage.draw(0, 0);
	ofPopMatrix();

	ofPushMatrix();
		//ofTranslate(m_position);
		m_player.render();
	ofPopMatrix();

	ofPushMatrix();
		m_bullet.render();
	ofPopMatrix();
}

// Begins the game - resets player ship and position
// as well as initializes all the asteroids.
void Game::begin() {

	// We're now playing the game - set state to Playing
	m_state = GameState::Playing;
}

void Game::updateShip() {

	//Movement controls
	if (ofGetKeyPressed('w')) {
		m_player.setSpeedY(-5.0f);
		//m_player.setSpeedX(0.0f);
	}
	else if (ofGetKeyPressed('s')) {
		m_player.setSpeedY(5.0f);
	}
	else {
		m_player.setSpeedY(0.0f);
	}

	if (ofGetKeyPressed('a')) {
		m_player.setSpeedX(-5.0f);
	}
	else if (ofGetKeyPressed('d')) {
		m_player.setSpeedX(5.0f);
	}
	else {
		m_player.setSpeedX(0.0f);
	}

	if (ofGetKeyPressed(' ')) // fire on space key
	{
		cout << getMousePosition().x << " " << getMousePosition().y << endl;
		if (false == m_bullet.isActive()) // only fire if the projectile is not already animating
		{
			m_bullet.fire(m_player.getPosition(), getMousePosition());
		}
	}

	//Update the player
	m_player.update();
}

ofVec2f Game::getMousePosition() {

	return ofVec2f (ofGetMouseX(), ofGetMouseY());
}

void Game::updateBullet() {
	m_bullet.update();
}

// Gets the game's current game state
Game::GameState Game::getGameState() {
	return m_state;
}
