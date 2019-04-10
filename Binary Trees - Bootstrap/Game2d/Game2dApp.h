#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "node.h"
#include "binary_tree.h"


class Game2dApp : public aie::Application {
public:

	Game2dApp();
	virtual ~Game2dApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	binary_tree<int>	m_binary_tree;
	node<int>*			m_selectedNode;
};