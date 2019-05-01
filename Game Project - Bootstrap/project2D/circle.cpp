#include "circle.h"
#include "Application2D.h"

circle::circle(float m_circlePosX, float m_circlePosY)
{
	circlePosX = m_circlePosX;
	circlePosY = m_circlePosY;
}


circle::~circle()
{
}


bool circle::update(float deltaTime, Application2D* app2D)
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
			app2D->updateHealth(1, 1);
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

float circle::get_radius()
{
	return m_radius;
}
