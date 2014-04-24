#include "GameElement_gravity.h"

GameElement_gravity::GameElement_gravity(engine::CSprite* sprite, sf::RenderWindow* window)
	: engine::CGravityBased(sprite)
{
	m_pSprite = sprite;
	m_pWindow = window;
}

void GameElement_gravity::render()
{
	m_pWindow->draw(*m_pSprite);
}
