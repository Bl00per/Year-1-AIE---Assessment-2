#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <Windows.h>
#include <iostream>
#include <ctime>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup()
{
	m_2dRenderer = new aie::Renderer2D();

	m_health = new aie::Texture("../bin/textures/HeartSpritesheet.png");
	m_gameoverLogo = new aie::Texture("../bin/textures/GameoverLogo.png");
	m_escape = new aie::Texture("../bin/textures/QuitESC.png");
	m_font = new aie::Font("./font/consolas_bold.ttf", 32);
	m_button = new Button();

	m_timer = 0;
	sprite_timer = 0;

	is_button_clicked = false;

	srand(time(NULL));

	return true;
}

void Application2D::shutdown()
{
	delete m_font;
	delete m_2dRenderer;
	delete m_health;
	delete m_gameoverLogo;
	delete m_escape;
	delete m_button;
}

void Application2D::update(float deltaTime)
{
	m_timer += deltaTime;
	sprite_timer += deltaTime;
	time_until_next_spawn -= deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	mousePosX = input->getMouseX();
	mousePosY = input->getMouseY();

	if (m_button->buttonClicked())
	{
		is_button_clicked = true;
	}

	// Check if Play button has been clicked
	if (is_button_clicked)
	{
		// Call the update function while i < count
		for (int i = 0; i < circle_array.count(); i++)
		{
			if (!circle_array[i].update(deltaTime, this))
			{
				circle_array.remove(i);
			}
		}

		if (TotalHearts > 0)
		{
			for (int i = 0; i < circle_array.count(); i++)
			{
				if (detect_collision(&circle_array[i], mousePosX, mousePosY) && input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
				{
					circle_array.remove(i);
				}

				else if (!detect_collision(&circle_array[i], mousePosX, mousePosY) && input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
				{
					if (NumberHeartsLoss >= 3)
						NumberHeartsLoss = 3; // Set sprite to display no hearts
					else
					{
						NumberHeartsLoss++; // Update sprite
						TotalHearts--; // Update health
					}
				}
			}
		}

		for (int i = 0; i < circle_array.count(); i++)
		{
			if (detect_collision(&circle_array[i], mousePosX, mousePosY))
			{
				circle_array[i].setHovering(true);
			}

			else
			{
				circle_array[i].setHovering(false);
			}
		}

		generatePositionX(deltaTime);
		generatePositionY(deltaTime);

		// Push a circle to the dynamic array every 1 second, decreasing over time
		if (time_until_next_spawn < 0)
		{
			circle_array.push(circle(objectPosX, objectPosY));

			time_until_next_spawn = 1 / spawns_per_second;
			std::cout << "Tick at: " << spawns_per_second << std::endl;
			spawns_per_second += 0.04f;
		}

		//std::cout << "Current time until next spawn: " << time_until_next_spawn << std::endl;
		//std::cout << "The current mouse position is: " << mousePosX << "/" << mousePosY << std::endl;
		//std::cout << "Current random numbers: " << objectPosX << '/' << objectPosY << std::endl;

		// exit the application
		if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
			quit();
	}
}

void Application2D::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// set the UV for all sprites
	m_2dRenderer->setUVRect(0, 0, 1, 1);

	// Draw and Update heart spritesheet/health
	//              			Across				Down	             Where across/Where down
	m_2dRenderer->setUVRect(1.0f / 1.0f, (float)NumberHeartsLoss / 4.0f, 1.0f / 1.0f, 1.0 / 4.0f);
	m_2dRenderer->drawSprite(m_health, 1063, 60, 418, 103, 0, 0.9);

	// Every time a circle is pushed in circle::update, draw a circle to the screen
	for (int i = 0; i < circle_array.count(); i++)
	{
		circle_array[i].draw(m_2dRenderer);
	}

	if (TotalHearts <= 0)
	{
		m_2dRenderer->setUVRect(0, 0, 1, 1);
		m_2dRenderer->setRenderColour(1, 1, 1, 1);
		m_2dRenderer->drawSprite(m_gameoverLogo, 640, 380,
			m_gameoverLogo->getWidth() / 1.5f, m_gameoverLogo->getHeight() / 1.5f, 0, 0);
		m_2dRenderer->drawSprite(m_escape, 640, 315,
			m_escape->getWidth() / 4, m_escape->getHeight() / 4, 0, 0);
	}

	// Draw button
	if (!is_button_clicked)
	{
		m_button->draw(m_2dRenderer);
	}

	// output some text
	m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

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

void Application2D::updateHealth(int a_removeHeart, int a_removeTotalHearts)
{

	if (NumberHeartsLoss >= 3)
		NumberHeartsLoss = 3; // If all hearts are gone, keep it gone
	else
	{
		// When the circle disappears, subtract a heart 
		NumberHeartsLoss += a_removeHeart;
		TotalHearts -= a_removeTotalHearts;
	}
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

void Application2D::generatePositionX(float deltaTime)
{
	// Get a random X position to spawn the circles
	objectPosX = rand() % 1280 + 0;
}

void Application2D::generatePositionY(float deltaTime)
{
	// Get a random Y position to spawn the circles
	objectPosY = rand() % 720 + 0;
}
