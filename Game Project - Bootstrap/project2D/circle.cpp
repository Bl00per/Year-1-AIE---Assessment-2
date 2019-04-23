#include "circle.h"

#include <ctime>




circle::circle()
{
	srand(time(NULL));
	circlePosX = rand() % getWindowWidth() + 0;
}


circle::~circle()
{
}


void circle::update(float deltaTime)
{

}

void circle::draw()
{

}