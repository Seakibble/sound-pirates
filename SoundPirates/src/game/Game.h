#include "ofMain.h"
#include "AllHeaders.h"
#include "GameObject.h"
#include "Bullet.h"

class Game
{
public:
	enum GameState
	{
		NotInitialized,
		Ready,
		Playing,
		GameWin,
		GameOver
	};

	Game();
	~Game();

	void init();
	void update();
	void render();

	void begin();

	GameState getGameState();

	ofVec2f getMousePosition();

private:
	void updateShip();
	void updateBullet();

	GameState m_state;
	GameObject m_player;

	ofImage m_bgImage;

	Bullet m_bullet[100];
};