#include "Renderer2D.h"
#include "Bullet.h"
#include <vector>

class Asteroid
{
public:
	Asteroid();

	~Asteroid();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

protected:
	aie::Texture*		m_asteroid;
	float positionX = 650;
	float positionY = 500;
	float rotation = 0; //degrees


	int screenWidth = 1280;
	int screenHeight = 720;
};

