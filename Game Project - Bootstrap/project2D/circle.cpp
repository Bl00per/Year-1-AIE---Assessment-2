#include "circle.h"

#include <ctime>

circle::circle(float m_circlePosX, float m_circlePosY)
{
	srand(time(NULL));
	circlePosX = m_circlePosX;
	circlePosY = m_circlePosY;
}


circle::~circle()
{
}


void circle::update(float deltaTime)
{
	m_timer += deltaTime;
	m_raidus += deltaTime * 3;


}

void circle::draw(aie::Renderer2D*	m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 0, 0.25, 1);
	m_2dRenderer->drawCircle(circlePosX, circlePosY, m_raidus);
}