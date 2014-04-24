#ifndef GAMEELEMENT_MOVEABLE_H_
#define GAMEELEMENT_MOVEABLE_H_

#include "Physics/CMovable.h"

#include "Graphic/CSprite.h"
#include "Graphic/CRenderable.h"

class GameElement_movable: public engine::CMovable, public engine::CRenderable
{
public:
	GameElement_movable(engine::CSprite* sprite, int zorder);
};

#endif /* GAMEELEMENT_MOVEABLE_H_ */
