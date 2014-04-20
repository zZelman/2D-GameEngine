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
		// TODO: finish n^2 collision


		unsigned int i = 0, n = 0;
		TRect<int> moving, moving_vertical;
		float vel_x, vel_y;
		bool hasCollided;
		std::list<CMovable*> move_normally;

		// Movable Objects -> Static Collidable Objects
		CCollidable* pC = NULL;
		CMovable* pM = NULL;
		for (i = 0; i < m_movables.size(); ++i)
		{
			hasCollided = false;

			pM = m_movables[i];

			pM->setIsSideBlocked(false, false, false, false);

			pM->getRect(&moving);
			pM->getVelosity(vel_x, vel_y);
			moving.movePosition(vel_x, vel_y);

			for (n = 0; n < m_collidables.size(); ++n)
			{
				pC = m_collidables[n];

				if (pC->isCollision(&moving))
				{
					hasCollided = true;
					resolve_collision(pM, vel_x, vel_y, pC);
				}

				pM->determine_sideBlocked(pC);
			}

			pM->print();
			std::cout << std::endl;

			if (!hasCollided)
			{
				move_normally.push_front(pM);
			}
		}

		applyMoveNormally(&move_normally);
	}


	void PhysicsEngine::applyMoveNormally(std::list<CMovable*>* list) const
	{
		for (std::list<CMovable*>::iterator itr = list->begin();
		        itr != list->end();
		        ++itr)
		{
			(*itr)->move_normally();
		}
	}


	void PhysicsEngine::resolve_collision(CMovable* m, float vel_x, float vel_y, CCollidable* c) const
	{
		struct SSideBlocked s;
		m->getIsSideBlocked(s);

		if (vel_x > 0 && !s.right) // moving right, and is not blocked right
		{
			m->setLeft(c->getLeft() - m->getWidth());
		}
		else if (vel_x < 0 && !s.left) // moving left, and is not blocked left
		{
			m->setLeft(c->getLeft() + c->getWidth());
		}

		if (vel_y > 0 && !s.down) // moving down, and is not blocked down
		{
			m->setTop(c->getTop() - m->getHeight());
		}
		else if (vel_y < 0 && !s.up) // moving up, and is not blocked up
		{
			m->setTop(c->getTop() + c->getHeight());
		}
	}


} /* namespace engine */
