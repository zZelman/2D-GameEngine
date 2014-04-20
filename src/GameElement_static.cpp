#include "GameElement_static.h"

GameElement_static::GameElement_static(CSprite* sprite,
                                       sf::RenderWindow* window)
	: engine::CCollidable(sprite)
{
	m_pSprite = sprite;
	m_pWindow = window;
}

void GameElement_static::render()
{
	m_pWindow->draw(*m_pSprite);
}
