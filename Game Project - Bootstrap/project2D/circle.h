#pragma once

#include "Application2D.h"
#include "Renderer2D.h"
#include "Input.h"
#include <iostream>

class circle
{
public:
	circle();

	~circle();


	void update(float deltaTime);
	void draw();

private:
	int circlePosX = 0;
	int circlePosY = 0;
	float m_raidus = 0.0f;

};

