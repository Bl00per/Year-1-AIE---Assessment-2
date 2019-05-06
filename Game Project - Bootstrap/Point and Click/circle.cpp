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
	}

	// This is for the colour changing why the cursor is hovering over the circle
	if (m_is_hovering)
	{
		if (!redComplete)
		{
			// If blue is greater than 0, bring it down to 0
			if (m_blue > 0)
			{
				m_blue -= deltaTime;
			}

			// Increase red over time
			m_red += deltaTime;

			if (m_red >= 1)
			{
				redComplete = true;
			}
		}
		else if (redComplete && !greenComplete)
		{
			m_red -= deltaTime; // Slowly decrease red
			m_green += deltaTime; // Slowly increase green

			if (m_green >= 1)
			{
				greenComplete = true;
			}
		}
		else if (greenComplete)
		{
			m_green -= deltaTime; // Slowly decrease green
			m_blue += deltaTime; // Slowly increase blue

			// If blue reaches max, set both to false to restart the loop
			if (m_blue >= 1)
			{
				redComplete = false;
				greenComplete = false;
			}
		}
	}
	else
	{
		m_red = 1.0f;
		m_blue = 0.25f;
		m_green = 0;
	}

	return true;
}

void circle::draw(aie::Renderer2D*	m_2dRenderer)
{
	if (m_is_hovering)
	{
		m_2dRenderer->setRenderColour(m_red, m_green, m_blue, circleAlpha);
	}
	else
	{
		m_2dRenderer->setRenderColour(1, 0, 0.25f, circleAlpha);
	}

	m_2dRenderer->drawCircle(circlePosX, circlePosY, m_radius);
}

float circle::get_radius()
{
	return m_radius;
}

void circle::setHovering(bool a_is_hovering)
{
	m_is_hovering = a_is_hovering;
}
