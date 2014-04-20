#ifndef GAMEELEMENT_GRAVITY_H_
#define GAMEELEMENT_GRAVITY_H_

#include "Physics/CGravityBased.h"

class GameElement_gravity: public engine::CGravityBased
{
public:
	GameElement_gravity(CSprite* sprite, sf::RenderWindow* window);

	void render();
private:
	sf::RenderWindow* m_pWindow;
	CSprite* m_pSprite;
};

#endif /* GAMEELEMENT_GRAVITY_H_ */
