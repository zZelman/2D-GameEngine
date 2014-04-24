#include "GameElement_movable.h"

GameElement_movable::GameElement_movable(engine::CSprite* sprite, int zorder)
	: engine::CMovable(sprite), engine::CRenderable(sprite, zorder)
{
}
