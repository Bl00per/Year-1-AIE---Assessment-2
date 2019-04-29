#pragma once

#include "Renderer2D.h"
#include "Input.h"
#include <iostream>

class circle
{
public:
	circle() {};
	circle(float m_circlepositionX, float m_circlepositionY);

	~circle();


	void update(float deltaTime);
	void draw(aie::Renderer2D*	m_2dRenderer);

private:
	aie::Renderer2D*	m_2dRenderer;
	float m_timer;

	float circlePosX = 0;
	float circlePosY = 0;
	float m_raidus = 5.0f;

};

