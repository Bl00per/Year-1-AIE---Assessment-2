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


bool circle::update(float deltaTime)
{
	m_timer += deltaTime;
	m_radius += deltaTime * 5;

	// 38 is max radius
	if (m_radius >= 35.0f)
	{
		circleAlpha -= 0.6 * deltaTime;
		m_radius = 35.0f;
		if (circleAlpha <= 0)
		{
			circleAlpha = 0;
			return false;
		}
		return true;
	}

}

void circle::draw(aie::Renderer2D*	m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 0, 0.25, circleAlpha);
	m_2dRenderer->drawCircle(circlePosX, circlePosY, m_radius);
}