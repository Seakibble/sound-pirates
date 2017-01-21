#pragma once

#include "ofMain.h"
#include "../ProjectConstants.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void init();
	void update();
	void render();

	void loadImage(static const string _asset);

	void setPos(ofVec3f _newPos);
	void setPos(float _newX, float _newY);
	void setPosX(float _newX);
	void setPosY(float _newY);
	void setPosZ(float _newZ);

	void setSpeed(ofVec3f _newSpeed);
	void setSpeed(float _newX, float _newY);
	void setSpeedX(float _newX);
	void setSpeedY(float _newY);


private:
	ofVec3f m_pos;
	ofVec3f m_speed;

	ofImage m_sprite;
	ofVec2f m_size;
};
