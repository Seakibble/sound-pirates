#include "ofMain.h"
#include "GameObject.h"

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

private:
	GameState             m_state;

	GameObject m_player;

	ofImage m_bgImage;
};