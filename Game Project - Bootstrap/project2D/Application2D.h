#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "circle.h"
#include "dynamic_array.h"
#include <Windows.h>
#include <vector>

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	bool waitingForPlayer();

	dynamic_array<circle> circle_array;
	
	void generatePositionX(float deltaTime);
	void generatePositionY(float deltaTime);

	float getMousePosX();
	float getMousePosY();

	void updateHealth(int a_removeHeart, int a_removeTotalHearts);

	void ClearScreen()
	{
		HANDLE                     hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD                      count;
		DWORD                      cellCount;
		COORD                      homeCoords = { 0, 0 };

		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE) return;

		/* Get the number of cells in the current buffer */
		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
		cellCount = csbi.dwSize.X *csbi.dwSize.Y;

		/* Fill the entire buffer with spaces */
		if (!FillConsoleOutputCharacter(
			hStdOut,
			(TCHAR) ' ',
			cellCount,
			homeCoords,
			&count
		)) return;

		/* Fill the entire buffer with the current colors and attributes */
		if (!FillConsoleOutputAttribute(
			hStdOut,
			csbi.wAttributes,
			cellCount,
			homeCoords,
			&count
		)) return;

		/* Move the cursor home */
		SetConsoleCursorPosition(hStdOut, homeCoords);
	}

protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_health;
	aie::Texture*		m_gameoverLogo;
	aie::Texture*		m_escape;
	circle*				circleObject;

	// Get the X & Y positions of the mouse
	float mousePosX = 0.0f;
	float mousePosY = 0.0f;

	// Object positions to pass to the circles
	float objectPosX = 0;
	float objectPosY = 0;

	float m_timer;

	// Timer to increase circle spawn rate as the game progress
	float time_until_next_spawn = 3.0f;
	float spawns_per_second = 0.12f;

	// Sprite stuff
	float sprite_timer;
	int NumberHeartsLoss = 0;
	int TotalHearts = 3;

	// Collision Detection
	bool detect_collision(circle* a_circle, float a_mousePosX, float a_mousePosY);
};