#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"


Application2D::Application2D()
{
}

Application2D::~Application2D()
{
}

bool Application2D::startup()
{
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./bin/font/consolas_bold.ttf", 32);
	m_health = new aie::Texture("./bin/textures/HeartSpritesheet.png");
	m_gameoverLogo = new aie::Texture("./bin/textures/GameoverLogo.png");
	m_buttonPlay = new Button_play();
	m_buttonRetry = new Button_retry();
	m_buttonQuit = new Button_quit();

	m_timer = 0;
	end_timer = SMOL_DELAY;
	score_timer = 0;
	survive_timer = 0;

	isButtonClicked_Play = false;
	isButtonClicked_Retry = false;
	isButtonClicked_Quit = false;

	srand(time(NULL));

	return true;
}

void Application2D::shutdown()
{
	delete m_2dRenderer;
	delete m_font;
	delete m_health;
	delete m_gameoverLogo;
	delete m_buttonPlay;
	delete m_buttonRetry;
	delete m_buttonQuit;
	circle_array.clear();
}

void Application2D::update(float deltaTime)
{
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	Button_retry retryButton;

	// Get mouse coordinates
	mousePosX = input->getMouseX();
	mousePosY = input->getMouseY();

	// Generate the position of the circle spawn
	generatePositionX(deltaTime);
	generatePositionY(deltaTime);

	// Check if buttons have been pressed
	if (m_buttonPlay->buttonClickedPlay())
	{
		isButtonClicked_Play = true;
	}

	// Only make the buttons usable once end timer has reached 0
	if (end_timer <= 0)
	{
		if (m_buttonRetry->buttonClickedRetry())
		{
			isButtonClicked_Retry = true;
		}

		if (m_buttonQuit->buttonClickedQuit())
		{
			isButtonClicked_Quit = true;
		}
	}

	// Check if Play button has been clicked
	if (isButtonClicked_Play)
	{
		// Timer starts when the play button has been clicked
		time_until_next_spawn -= deltaTime;
		if (TotalHearts > 0)
		{
			score_timer += deltaTime;
			survive_timer += deltaTime;
		}

		// Every 1/2 a second the player lasts, increase score by 1
		if (score_timer > 0.5f)
		{
			playerScore += 1;
			score_timer = 0;
		}

		// Track the time survived
		if (survive_timer >= 1.0)
		{
			timeSurvivedSEC += 1;
			survive_timer = 0;

			if (timeSurvivedSEC == 60)
			{
				timeSurvivedMIN += 1;
				timeSurvivedSEC = 0;
			}
		}

		// Call the update function while i < count
		for (int i = 0; i < circle_array.count(); i++)
		{
			if (!circle_array[i].update(deltaTime, this))
			{
				circle_array.remove(i);
			}
		}

		// While the player has hearts, keep playing
		if (TotalHearts > 0 && input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
		{
			bool clickHit = false;

			for (int i = 0; i < circle_array.count(); i++)
			{
				if (detect_collision(&circle_array[i], mousePosX, mousePosY))
				{
					circle_array.remove(i);
					playerScore += 10;
					clickHit = true;
				}
			}

			if (!clickHit)
			{
				if (NumberHeartsLoss >= 3)
					NumberHeartsLoss = 3; // Set sprite to display no hearts
				else
				{
					NumberHeartsLoss++; // Update sprite
					TotalHearts--; // Update health
				}
			}
		}

		// If the cursor is hovering a circle, make it cycle the colours
		for (int i = 0; i < circle_array.count(); i++)
		{
			if (detect_collision(&circle_array[i], mousePosX, mousePosY))
			{
				circle_array[i].setHovering(true);
			}

			else
			{
				circle_array[i].setHovering(false);
			}
		}

		// Push a circle to the dynamic array every 1 second, decreasing over time
		if (time_until_next_spawn < 0)
		{
			circle_array.push(circle(objectPosX, objectPosY));

			time_until_next_spawn = 1 / spawns_per_second;
			//std::cout << "Tick at: " << spawns_per_second << std::endl;
			spawns_per_second += 0.04f;
		}

		if (TotalHearts <= 0)
		{
			end_timer -= deltaTime;
		}

		// Retry button
		if (isButtonClicked_Retry && TotalHearts == 0)
		{
			NumberHeartsLoss = 0;
			TotalHearts = 3;
			spawns_per_second = 0.12f;
			time_until_next_spawn = 3.0f;
			timeSurvivedMIN = 0;
			timeSurvivedSEC = 0;
			playerScore = 0;
			circle_array.clear();
			end_timer = SMOL_DELAY;
			isButtonClicked_Retry = false;
		}

		// Quit button
		if (isButtonClicked_Quit && TotalHearts == 0)
		{
			quit();
		}
	}
	// Exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
}

void Application2D::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// set the UV for all sprites
	m_2dRenderer->setUVRect(0, 0, 1, 1);

	// Draw and Update heart spritesheet/health
	//              			Across				Down	             Where across/Where down
	m_2dRenderer->setUVRect(1.0f / 1.0f, (float)NumberHeartsLoss / 4.0f, 1.0f / 1.0f, 1.0 / 4.0f);
	m_2dRenderer->drawSprite(m_health, 1115, 47, 314, 77, 0, 0.9);

	// Every time a circle is pushed in circle::update, draw a circle to the screen
	for (int i = 0; i < circle_array.count(); i++)
	{
		circle_array[i].draw(m_2dRenderer);
	}

	char endtime[32];
	// If the player has run out of hearts, display the gameover screen
	if (TotalHearts <= 0)
	{
		// Game over sprite
		m_2dRenderer->setUVRect(0, 0, 1, 1);
		m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
		m_2dRenderer->drawSprite(m_gameoverLogo, 640, 380,
			m_gameoverLogo->getWidth() / 1.5f, m_gameoverLogo->getHeight() / 1.5f, 0, 0);

		// Quit button sprite
		m_buttonQuit->draw(m_2dRenderer);

		// Retry button sprite
		m_buttonRetry->draw(m_2dRenderer);

		if (timeSurvivedSEC < 10)
		{
			sprintf_s(endtime, 32, "Time Survived: %i:0%i", getTimeSurvivedMIN(), getTimeSurvivedSEC());
		}
		else
		{
			sprintf_s(endtime, 32, "Time Survived: %i:%i", getTimeSurvivedMIN(), getTimeSurvivedSEC());
		}
		m_2dRenderer->drawText(m_font, endtime, 475, 160);
	}

	// Draw button
	if (!isButtonClicked_Play)
	{
		m_buttonPlay->draw(m_2dRenderer);
	}

	// output some text
	m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	char score[32];
	sprintf_s(score, 32, "Score: %i", getPlayerScore());
	m_2dRenderer->drawText(m_font, score, 2, 720 - 32);

	// done drawing sprites
	m_2dRenderer->end();
}

float Application2D::getMousePosX()
{
	return mousePosX;
}

float Application2D::getMousePosY()
{
	return mousePosY;
}

void Application2D::updateHealth(int a_removeHeart, int a_removeTotalHearts)
{

	if (NumberHeartsLoss >= 3)
		NumberHeartsLoss = 3; // If all hearts are gone, keep it gone
	else
	{
		// When the circle disappears, subtract a heart 
		NumberHeartsLoss += a_removeHeart;
		TotalHearts -= a_removeTotalHearts;
	}
}

bool Application2D::detect_collision(circle* a_circle, float a_mousePosX, float a_mousePosY)
{
	float xDistance = a_circle->GetPosX() - a_mousePosX;
	float yDistance = a_circle->GetPosY() - a_mousePosY;

	float distance = sqrt(xDistance * xDistance + yDistance * yDistance);

	if (distance < a_circle->get_radius())
	{
		return true;
	}
	return false;
}

// Get a random X position to spawn the circles
void Application2D::generatePositionX(float deltaTime)
{
	objectPosX = rand() % 1260 + 10;
}

// Get a random Y position to spawn the circles
void Application2D::generatePositionY(float deltaTime)
{
	objectPosY = rand() % 700 + 10;
}

int Application2D::getPlayerScore()
{
	return playerScore;
}

int Application2D::getTimeSurvivedSEC()
{
	return timeSurvivedSEC;
}

int Application2D::getTimeSurvivedMIN()
{
	return timeSurvivedMIN;
}