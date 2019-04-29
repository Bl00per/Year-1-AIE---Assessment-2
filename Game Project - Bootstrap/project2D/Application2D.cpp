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

	m_font = new aie::Font("./font/consolas_bold.ttf", 32);
	
	m_timer = 0;
	sprite_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;
	sprite_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	objectPosX = rand() % 1280 + 0;
	objectPosY = rand() % 720 + 0;

	mousePosX = input->getMouseX();
	mousePosY = input->getMouseY();
	std::cout << "The current mouse position is: " << mousePosX << "/" << mousePosY << std::endl;

	// Call the update function while i < count
	for (int i = 0; i < circle_array.count(); i++)
	{
		circle_array[i].update(deltaTime);
	}

	// Push a circle to the dynamic array every 1 second
	if (m_timer >= 1.0f)
	{
		circle_array.push(circle(objectPosX, objectPosY));
		m_timer = 0;
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
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	
	//if (sprite_timer >= 0.05f) {
	//	sprite_timer = 0.0f;

	//	across_sprite++;
	//	if (across_sprite == 10) {
	//		across_sprite = 0;
	//		down_sprite++;
	//		if (down_sprite == 6) {
	//			down_sprite = 0;
	//		}
	//	}
	//}

	//// demonstrate animation			Across				Down	Where across/Where down
	//m_2dRenderer->setUVRect((float)across_sprite / 10.0f, (float)down_sprite / 6.0f, 1.0f / 10.0f, 1.0/6.0f);
	//m_2dRenderer->drawSprite(m_fire, 640, 270, 500, 200, 0, 0.8f);

	// Every time a circle is pushed in update, draw a circle to the screen
	for (int i = 0; i < circle_array.count(); i++)
	{
		circle_array[i].draw(m_2dRenderer);
	}
	

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}