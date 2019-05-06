#pragma once

#include "Renderer2D.h"
#include "Input.h"
#include "Texture.h"
#include "Button.h"

class Button_quit
{
public:
	Button_quit();
	~Button_quit();

	void draw(aie::Renderer2D* renderer);
	bool update();

	bool buttonClickedQuit();

private:
	aie::Texture*	m_quit;

	float m_posX = 751;
	float m_posY = 298;
	float m_width = 216;
	float m_height = 76;

	bool buttonHovered = false;
};

