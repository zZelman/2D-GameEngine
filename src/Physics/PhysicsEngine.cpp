#include "PhysicsEngine.h"

#include <iostream>

namespace engine
{


	PhysicsEngine::PhysicsEngine()
	{
	}


	PhysicsEngine::~PhysicsEngine()
	{
	}


	void PhysicsEngine::addCollidable(CCollidable* c)
	{
		m_collidables.push_back(c);
	}


	void PhysicsEngine::addMovable(CMovable* m)
	{
		m_movables.push_back(m);
	}


	void PhysicsEngine::update()
	{
		n2_collision();
	}


	void PhysicsEngine::n2_collision()
	{
		unsigned int i = 0, n = 0;
		TRect<int> from, to;

		// Movable Objects -> Static Collidable Objects
		CCollidable* pC = NULL;
		CMovable* pM = NULL;
		for (i = 0; i < m_movables.size(); ++i)
		{
			pM = m_movables[i];
			pM->getRect(&from);
			for (n = 0; n < m_collidables.size(); ++n)
			{
				pC = m_collidables[n];
				pC->getRect(&to);

				if (pM->isCollision(&to))
				{
					resolve_move_collide(pM, pC);
				}
			}
		}
	}


	void PhysicsEngine::resolve_move_collide(CMovable* m, CCollidable* c)
	{
		std::cout << "resolve_move_collide" << std::endl;
	}


} /* namespace engine */
