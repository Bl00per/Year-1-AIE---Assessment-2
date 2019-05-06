#pragma once
#include "Renderer2D.h"
#include "Input.h"
#include "Texture.h"

class Button_retry
{
public:
	Button_retry();
	~Button_retry();

	void draw(aie::Renderer2D* renderer);
	bool update();

	bool buttonClicked();

private:
	aie::Texture*	m_retry;

	float m_posX = 529;
	float m_posY = 298;
	float m_width = 216;
	float m_height = 76;

	bool buttonHovered = false;
};

