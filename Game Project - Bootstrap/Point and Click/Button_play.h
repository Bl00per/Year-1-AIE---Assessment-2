#pragma once

#include "Renderer2D.h"
#include "Input.h"
#include "Texture.h"
#include "Button.h"

class Button_play
{
public:
	Button_play();
	~Button_play();

	void draw(aie::Renderer2D* renderer);
	bool update();

	bool buttonClickedPlay();

private:
	aie::Texture*	m_play;

	float m_posX = 640;
	float m_posY = 360;
	float m_width = 590;
	float m_height = 185;

	bool buttonHovered = false;
};

