#pragma once

#include "Renderer2D.h"
#include "Input.h"
#include <iostream>

class Application2D;

class circle
{
public:
	circle() {};
	circle(float m_circlepositionX, float m_circlepositionY);

	~circle();


	bool update(float deltaTime, Application2D* app2D);
	void draw(aie::Renderer2D*	m_2dRenderer);
	
	float get_radius();

	float GetPosX() const { return circlePosX; }
	float GetPosY() const { return circlePosY; }

	void setHovering(bool a_is_hovering);


protected:
	aie::Renderer2D*	m_2dRenderer;
	float m_timer;

	float m_red = 0.0f;
	float m_green = 0.0f;
	float m_blue = 0.0f;
	bool redComplete = false;
	bool greenComplete = false;

	bool m_is_hovering = false;

	float circlePosX = 0;
	float circlePosY = 0;
	float m_radius = 5.0f;
	float circleAlpha = 1;
};

