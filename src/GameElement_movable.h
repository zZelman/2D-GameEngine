#ifndef GAMEELEMENT_MOVEABLE_H_
#define GAMEELEMENT_MOVEABLE_H_

#include "Physics/CMovable.h"

#include "Graphic/CSprite.h"

class GameElement_movable: public engine::CMovable
{
public:
	GameElement_movable(CSprite* sprite, sf::RenderWindow* window);

	void render();
private:
	sf::RenderWindow* m_pWindow;
	CSprite* m_pSprite;
};

#endif /* GAMEELEMENT_MOVEABLE_H_ */
