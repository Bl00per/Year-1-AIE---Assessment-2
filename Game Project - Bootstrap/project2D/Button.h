#pragma once
#include "Renderer2D.h"

class Button
{

	void draw(aie::Renderer2D* renderer);
	void update();

};

class ButtonOfSpecificType : public Button
{
	//Only add functions here that are unique to this version.
};