#pragma once

#include "ofMain.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void    init();
	void    update();
	void    render();

	// fires the Bullet from a starting position towards a direction
	void    fire(const ofVec2f& _position, const ofVec2f& _direction);

	ofVec2f getPosition();
	float   getRadius();

private:
	ofVec2f     m_position;
	ofVec2f     m_velocity;
	float       m_boundingRadius;

	ofImage     m_image;
};
