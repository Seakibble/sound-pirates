#include "Bullet.h"
#include "ProjectConstants.h"

Bullet::Bullet()
	: m_position(0.0f, 0.0f)
	, m_velocity(0.0f, 0.0f)
	, m_boundingRadius(0.0f)
{
}

Bullet::~Bullet() {
}

void Bullet::init() {
	m_image.load(ProjectConstants::IMG_PATH_BULLET);
	m_boundingRadius = m_image.getWidth() * 0.5f;
}

void Bullet::update() {
	m_position = m_position + m_velocity;
}

void Bullet::render() {
	ofSetRectMode(OF_RECTMODE_CENTER);

	// draw asteroid
	ofPushMatrix();
	ofTranslate(m_position);

	ofSetColor(ofColor::white);
	m_image.draw(0, 0);
	ofPopMatrix();
}

void Bullet::fire(const ofVec2f& _position, const ofVec2f& _direction) {
	m_position = _position;
	m_velocity = _direction * 1.0f;
}

ofVec2f Bullet::getPosition() {
	return m_position;
}

float Bullet::getRadius() {
	return m_boundingRadius;
}
