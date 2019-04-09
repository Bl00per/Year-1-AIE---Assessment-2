#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	virtual void shooting(float deltaTime );

	float shipPosX = 640.0f;
	float shipPosY = 360.0f;

	float objectPosX = 640.0f;
	float objectPosY = 360.0f;
	float objectRotation = 0.0f;

	float roation_speed = 1;

	float bulletPosX = objectPosX;

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Texture*		m_background;
	aie::Texture*		m_attack;

	float m_timer;
	float sprite_timer;
	int across_sprite = 0;
	int down_sprite = 0;
};