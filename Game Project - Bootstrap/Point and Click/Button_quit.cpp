#include "Button_quit.h"


Button_quit::Button_quit()
{
	// Load a sprite to display as button
	m_quit = new aie::Texture("../bin/textures/QuitButton.png");
}


Button_quit::~Button_quit()
{
	delete m_quit;
}

bool Button_quit::update()
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
		//return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	buttonHovered = false;
	return false;
}

void Button_quit::draw(aie::Renderer2D* renderer)
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

	// Draw quit button sprite
	renderer->setUVRect(0, 0, 1.0f, 1.0f);
	renderer->drawSprite(m_quit, m_posX, m_posY, m_width, m_height);
}

bool Button_quit::buttonClickedQuit()
{
	if (update())
	{
		return true;
	}
	return false;
}