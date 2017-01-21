#pragma once

#include "ofMain.h"
#include "GameObject.h"


class Swarm {

public:
	Swarm();
	~Swarm();

	void init(int _size = 20);
	void update();
	void render();

private:

	std::vector<GameObject> swarm;

};