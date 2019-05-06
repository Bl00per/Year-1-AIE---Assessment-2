#include "Button.h"



Button::Button()
{
	// Load a sprite to display as button
	m_play = new aie::Texture("../bin/textures/PlayButton.png");
}

Button::~Button()
{
	delete m_play;
}

bool Button::update()
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
		return input->wasMouseButtonReleased(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	return false;
}

void Button::draw(aie::Renderer2D* renderer)
{
	aie::Input* input = aie::Input::getInstance();

	// Draw a coloured box for the button background
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	// Draw text on the button
	//renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);

	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		renderer->setRenderColour(0.5f, 0.5f, 0.5f, 0.5f);
	}
	
	// Draw play button sprite
	renderer->setUVRect(0, 0, 1.0f, 1.0f);
	renderer->drawSprite(m_play, m_posX, m_posY, m_width, m_height);
	

}

bool Button::buttonClicked()
{
	if (update())
	{
		return true;
	}
	return false;
}
