#ifndef GAMEELEMENT_GRAVITY_H_
#define GAMEELEMENT_GRAVITY_H_

#include "Physics/CGravityBased.h"
#include "Graphic/CSprite.h"

class GameElement_gravity: public engine::CGravityBased
{
public:
	GameElement_gravity(engine::CSprite* sprite, sf::RenderWindow* window);

	void render();
private:
	sf::RenderWindow* m_pWindow;
	engine::CSprite* m_pSprite;
};

#endif /* GAMEELEMENT_GRAVITY_H_ */
