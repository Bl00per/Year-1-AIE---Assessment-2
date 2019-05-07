#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "circle.h"
#include "dynamic_array.h"
#include "Button_play.h"
#include "Button_retry.h"
#include "Button_quit.h"
#include <Windows.h>
#include <iostream>
#include <ctime>

#define SMOL_DELAY 0.5f

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	dynamic_array<circle> circle_array;
	
	void generatePositionX(float deltaTime);
	void generatePositionY(float deltaTime);

	float getMousePosX();
	float getMousePosY();

	int getPlayerScore();
	int getTimeSurvivedSEC();
	int getTimeSurvivedMIN();


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
	aie::Texture*		m_health; // Health sprite
	aie::Texture*		m_gameoverLogo; // Gameover text
	circle*				circleObject; // Circles
	Button_play*		m_buttonPlay; // Play button
	Button_retry*		m_buttonRetry; // Retry Button
	Button_quit*		m_buttonQuit; // Quit button

	// Check if the button has been clicked on
	bool isButtonClicked_Play;
	bool isButtonClicked_Retry;
	bool isButtonClicked_Quit;

	// Get the X & Y positions of the mouse
	float mousePosX = 0.0f;
	float mousePosY = 0.0f;

	// Object positions to pass to the circles
	int objectPosX = 0;
	int objectPosY = 0;

	// Timers
	float m_timer;
	float end_timer;
	float score_timer;
	float survive_timer;

	// Timer to increase circle spawn rate as the game progress
	float time_until_next_spawn = 3.0f;
	float spawns_per_second = 0.12f;

	// Sprite stuff
	int NumberHeartsLoss = 0;
	int TotalHearts = 3;

	// Score system
	int playerScore = 0;

	// Ending spawn time
	int timeSurvivedSEC = 0;
	int timeSurvivedMIN = 0;

	// Collision Detection
	bool detect_collision(circle* a_circle, float a_mousePosX, float a_mousePosY);
};