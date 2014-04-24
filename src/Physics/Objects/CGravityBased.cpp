#include "../CGravityBased.h"

#include <iostream>

namespace engine
{

	CGravityBased::CGravityBased(CSprite* sprite)
		: CMovable(sprite)
	{
		isFirstUpdate = true;
		restartGravityClock();
		m_falling = true;
	}


	CGravityBased::~CGravityBased()
	{
	}


	float CGravityBased::getSeconds() const
	{
		return m_gravityTimer.getElapsedTime().asSeconds();
	}


	int32_t CGravityBased::getMilliseconds() const
	{
		return m_gravityTimer.getElapsedTime().asMilliseconds();
	}


	int64_t CGravityBased::getMicroseconds() const
	{
		return m_gravityTimer.getElapsedTime().asMicroseconds();
	}


	void CGravityBased::restartGravityClock()
	{
		m_gravityTimer.restart();
	}


	bool CGravityBased::isFalling() const
	{
		return m_falling;
	}


	void CGravityBased::setFalling(bool isFalling)
	{
		if (!m_falling && isFalling) // just started falling
		{
			restartGravityClock();
		}

		m_falling = isFalling;
	}

	void CGravityBased::collision_active(CCollidable* c)
	{
		std::cout << "CGravityBased::collision_active(CCollidable* c)"
		          << std::endl;
	}


	void CGravityBased::collision_active(CMovable* m)
	{
		std::cout << "CGravityBased::collision_active(CMovable* m)"
		          << std::endl;
	}


	void CGravityBased::collision_active(CGravityBased* g)
	{
		std::cout << "CGravityBased::collision_active(CGravityBased* g)"
		          << std::endl;
	}


	void CGravityBased::print() const
	{
		CMovable::print();

		std::cout << "fall:" << m_falling << " ";
	}

} /* namespace engine */
