#include "Bullet.h"
#include "ProjectConstants.h"

Bullet::Bullet()
	: m_position(0.0f, 0.0f)
	, m_velocity(0.0f, 0.0f)
	, m_boundingRadius(0.0f)
	, m_isActive(false)
{
}

Bullet::~Bullet() {
}

void Bullet::init() {
	m_image.load(ProjectConstants::IMG_PATH_BULLET);
	m_boundingRadius = m_image.getWidth() * 0.5f;
}

void Bullet::update() {
	if (false == m_isActive)
	{
		return;
	}

	m_position = m_position + m_velocity;

	// wrap if go past screen bounds
	if (m_position.x - m_boundingRadius > ofGetWindowWidth())
	{
		deactivate();
	}

	if (m_position.x + m_boundingRadius < 0)
	{
		deactivate();
	}

	if (m_position.y - m_boundingRadius > ofGetWindowHeight())
	{
		deactivate();
	}

	if (m_position.y + m_boundingRadius < 0)
	{
		deactivate();
	}
}

void Bullet::render() {
	if (false == m_isActive)
	{
		return;
	}

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
	m_velocity = _direction * 20.0f;

	m_isActive = true;
}

void Bullet::deactivate() {
	m_isActive = false;
}

bool Bullet::isActive() {
	return m_isActive;
}

ofVec2f Bullet::getPosition() {
	return m_position;
}

float Bullet::getRadius() {
	return m_boundingRadius;
}
