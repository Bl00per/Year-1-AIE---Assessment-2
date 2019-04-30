#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <Windows.h>
#include <iostream>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_health = new aie::Texture("../bin/textures/HeartSpritesheet.png");
	m_font = new aie::Font("./font/consolas_bold.ttf", 32);

	m_timer = 0;
	sprite_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
	delete m_health;
}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;
	sprite_timer += deltaTime;
	time_until_next_spawn -= deltaTime;
	//spawns_per_second += 0.05 * deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// Get a random X and Y position to spawn the circles
	objectPosX = rand() % 1280 + 0;
	objectPosY = rand() % 720 + 0;

	mousePosX = input->getMouseX();
	mousePosY = input->getMouseY();
	//std::cout << "The current mouse position is: " << mousePosX << "/" << mousePosY << std::endl;

	// Call the update function while i < count
	for (int i = 0; i < circle_array.count(); i++)
	{
		if (!circle_array[i].update(deltaTime))
		{
			circle_array.remove(i);
		}
	}

	for (int i = 0; i < circle_array.count(); i++)
	{
		if (detect_collision(&circle_array[i], mousePosX, mousePosY) && input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
		{
			circle_array.remove(i);

			if (down_sprite == 4)
				down_sprite = 4;
			else
			down_sprite--;
		}
	}

	// Push a circle to the dynamic array every 1 second
	if (time_until_next_spawn < 0)
	{
		circle_array.push(circle(objectPosX, objectPosY));

		time_until_next_spawn = 1 / spawns_per_second;
		std::cout << "Tick at: " << spawns_per_second << std::endl;
		spawns_per_second += 0.04f;
	}

	if (spawns_per_second >= 5.0f)
	{
		spawns_per_second = 5.0f;
	}


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// set the UV for all sprites
	m_2dRenderer->setUVRect(0, 0, 1, 1);

	// demonstrate animation			Across				Down	Where across/Where down
	m_2dRenderer->setUVRect((float)across_sprite / 1.0f, (float)down_sprite / 4.0f, 1.0f / 1.0f, 1.0/4.0f);
	m_2dRenderer->drawSprite(m_health, 640, 360, 900, 300, 0, 0.9);

	// Every time a circle is pushed in update, draw a circle to the screen
	for (int i = 0; i < circle_array.count(); i++)
	{
		circle_array[i].draw(m_2dRenderer);
	}
	

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->setRenderColour(1, 1, 1, 1);
	//m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}

float Application2D::getMousePosX()
{
	return mousePosX;
}

float Application2D::getMousePosY()
{
	return mousePosY;
}

bool Application2D::detect_collision(circle* a_circle, float a_mousePosX, float a_mousePosY)
{

	float xDistance = a_circle->GetPosX() - a_mousePosX;
	float yDistance = a_circle->GetPosY() - a_mousePosY;

	float distance = sqrt(xDistance * xDistance + yDistance * yDistance);

	if (distance < a_circle->get_radius())
	{
		return true;
	}
	return false;
}
