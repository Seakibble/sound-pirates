#pragma once

#include "GameObject.h"
#include "ProjectConstants.h"

//--------------------------------------------------------------
GameObject::GameObject() {
	
}

GameObject::~GameObject() {

}

void GameObject::init()
{
	setPos(0.0f, 0.0f);
	setSpeed(0.0f, 0.0f);
}

//--------------------------------------------------------------
void GameObject::update()
{
	m_pos += m_speed;

	if (m_pos.x <= 0) {
		m_pos.x = 0;
	}

	if (m_pos.x >= ProjectConstants::PROJ_WINDOW_RES_X) {
		m_pos.x = ProjectConstants::PROJ_WINDOW_RES_X;
	}

	if (m_pos.y <= 0) {
		m_pos.y = 0;
	}

	if (m_pos.y >= ProjectConstants::PROJ_WINDOW_RES_Y) {
		m_pos.y = ProjectConstants::PROJ_WINDOW_RES_Y;
	}
}


//--------------------------------------------------------------
void GameObject::render()
{
	ofPushMatrix();
	ofRectMode(OF_RECTMODE_CENTER);
	ofTranslate(m_pos);
	m_sprite.draw(0, 0);
	ofPopMatrix();
}



//-------------------------------------------------------
ofVec2f GameObject::getPosition() {
	return m_pos;
}

void GameObject::setPos(ofVec3f _newPos) {
	m_pos.set(_newPos);
}

void GameObject::setPos(float _newX, float _newY) {
	m_pos.set(_newX, _newY);
}

void GameObject::setPosX(float _newX) {
	m_pos.x = _newX;
}

void GameObject::setPosY(float _newY) {
	m_pos.y = _newY;
}

void GameObject::setPosZ(float _newZ) {
	m_pos.z = _newZ;
}

//-------------------------------------------------------
void GameObject::setSpeed(ofVec3f _newSpeed) {
	m_speed.set(_newSpeed);
}

void GameObject::setSpeed(float _newX, float _newY) {
	m_speed.set(_newX, _newY);
}

void GameObject::setSpeedX(float _newX) {
	m_speed.x = _newX;
}

void GameObject::setSpeedY(float _newY) {
	m_speed.y = _newY;
}

//--------------------------------------------------------------
void GameObject::loadImage(static const string _asset)
{
	m_sprite.loadImage(_asset);
	m_size.set(m_sprite.getWidth(), m_sprite.getHeight());
}
