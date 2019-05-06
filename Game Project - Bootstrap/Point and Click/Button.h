#pragma once

#include "Renderer2D.h"
#include "Button_play.h"
#include "Button_retry.h"
#include "Button_quit.h"

class Button
{
public:
	Button();
	~Button();

	virtual bool update();

protected:
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;

	bool buttonHovered = false;
};