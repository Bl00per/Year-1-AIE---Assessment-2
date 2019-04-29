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

	float mousePosX = 0.0f;
	float mousePosY = 0.0f;

	dynamic_array<circle> circle_array;
	//std::vector<circle> circleList;

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

	float objectPosX = 640;
	float objectPosY = 360;

	float m_timer;
	// Timer to increase circle spawn rate
	float time_until_next_spawn = 3.0f;
	float spawns_per_second = 0.12f;
	//float circle_timer_modifier = 0.3f;
	// Sprite stuff
	float sprite_timer;
	int across_sprite = 0;
	int down_sprite = 0;
};