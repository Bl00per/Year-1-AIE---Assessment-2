#include "Button_retry.h"
#include "Button.h"



Button_retry::Button_retry()
{
	// Load a sprite to display as button
	m_retry = new aie::Texture("../bin/textures/RetryButton.png");
}


Button_retry::~Button_retry()
{
	delete m_retry;
}

bool Button_retry::update()
{
	aie::Input* input = aie::Input::getInstance();

	// Get mouse position
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	// Calculate the 4 sides of the button
	float left = m_posX - (m_width * 0.5f);
	float right = m_posX + (m_width * 0.5f);
	float bottom = m_posY -(m_height * 0.5f);
	float top = m_posY + (m_height * 0.5f);
	
	// Check if the mouse is inside the box made by the 4 sides
	if (mouseX > left && mouseX < right && mouseY > bottom && mouseY < top)
	{
		// Return whether the mouse button is clicked while colliding
		buttonHovered = true;
		return input->wasMouseButtonReleased(aie::INPUT_MOUSE_BUTTON_LEFT);
		//return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	buttonHovered = false;
	return false;
}

void Button_retry::draw(aie::Renderer2D* renderer)
{
	aie::Input* input = aie::Input::getInstance();

	if (buttonHovered && input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		renderer->setRenderColour(0.5f, 0.5f, 0.5f, 0.5f);
	}
	else
	{
		renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	}

	// Draw retry button sprite
	renderer->setUVRect(0, 0, 1.0f, 1.0f);
	renderer->drawSprite(m_retry, m_posX, m_posY, m_width, m_height);
}

bool Button_retry::buttonClickedRetry()
{
	if (update())
	{
		return true;
	}
	return false;
}