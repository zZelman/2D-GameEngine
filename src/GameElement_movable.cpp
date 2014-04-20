#include "GameElement_movable.h"

GameElement_movable::GameElement_movable(CSprite* sprite, sf::RenderWindow* window)
	: engine::CMovable(sprite)
{
	m_pSprite = sprite;
	m_pWindow = window;
}

void GameElement_movable::render()
{
	m_pWindow->draw(*m_pSprite);
}
