#include "Button.h"

Button::Button()
{

}

Button::~Button()
{

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
	float bottom = m_posY - (m_height * 0.5f);
	float top = m_posY + (m_height * 0.5f);

	// Check if the mouse is inside the box made by the 4 sides
	if (mouseX > left && mouseX < right && mouseY > bottom && mouseY < top)
	{
		// Return whether the mouse button is clicked while colliding
		buttonHovered = true;
		return input->wasMouseButtonReleased(aie::INPUT_MOUSE_BUTTON_LEFT);
		//return input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	buttonHovered = false;
	return false;
}