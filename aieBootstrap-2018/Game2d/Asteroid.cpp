#include "Asteroid.h"
#include "Input.h"
#include "Texture.h"


Asteroid::Asteroid()
{
	m_asteroid = new aie::Texture("../bin/textures/rock_large.png"); // Medium sized
}

Asteroid::~Asteroid()
{
}

void Asteroid::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();

	rotation += deltaTime;

	// Cannot pass screen width
	if (positionX <= 0)
		positionX = 0;
	else if (positionX >= screenWidth)
		positionX = screenWidth;

	// Cannot pass screen height
	if (positionY <= 0)
		positionY = 0;
	else if (positionY >= screenHeight)
		positionY = screenHeight;
}

void Asteroid::draw(aie::Renderer2D* m_2dRenderer) {
	aie::Input* input = aie::Input::getInstance();

	// Position and draw the asteroids
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);

	// Small sized
	m_2dRenderer->drawSprite(m_asteroid, positionX, positionY, 0, 0, rotation, 0.9);

	// Medium sized
	m_2dRenderer->drawSprite(m_asteroid, positionX + 100, positionY, 96, 104, rotation, 0.9);

	// Large sized
	m_2dRenderer->drawSprite(m_asteroid, positionX + 300, positionY, 192, 208, rotation, 0.9);
}