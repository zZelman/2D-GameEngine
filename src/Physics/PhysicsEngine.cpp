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


	void PhysicsEngine::addGravityBased(CGravityBased* g)
	{
		m_gravityBased.push_back(g);
	}


	void PhysicsEngine::update()
	{
		n2_collision();
	}


	void PhysicsEngine::n2_collision()
	{
		// TODO: finish n^2 collision

		std::list<CMovable*> move_normally;

		// Movable Objects -> Static Collidable Objects
		n2_collision_move_static(&move_normally);

		// GravityBased Objects -> static Collidable Objects
		n2_collision_gravity_static(&move_normally);

		// Move the things that did not collide this update step
		apply_moveNormally(&move_normally);
	}


	void PhysicsEngine::n2_collision_move_static(std::list<CMovable*>* move_normally)
	{
		unsigned int i = 0, n = 0;
		TRect<int> moving_horizontal, moving_vertical;
		float vel_x, vel_y;
		bool hasCollided;
		CCollidable* pC = NULL;
		CMovable* pM 	= NULL;

		// iterate through movable objects
		for (i = 0; i < m_movables.size(); ++i)
		{
			pM = m_movables[i];


			//////////////////////////////////////////////////
			//
			// Updating blocked flags
			//
			/////////////////////////////////////////////////

			// reset block flags for all edges
			pM->setIsSideBlocked(false, false, false, false);
			// check if any side is blocked for this movable to any
			// static object
			for (n = 0; n < m_collidables.size(); ++n)
			{
				pC = m_collidables[n];
				pM->determine_sideBlocked(pC);
			}

			pM->print();
			// if a block is found, then the respective velocity will be set to 0
			// before collision detection
			pM->getVelosity(vel_x, vel_y);
			fix_blockedVelosities<CMovable>(pM, vel_x, vel_y);
			pM->print();
			std::cout << std::endl;


			//////////////////////////////////////////////////
			//
			// Begin collision detection & resolution
			//
			/////////////////////////////////////////////////

			// reset relevant vars in prep for collision detection
			hasCollided = false;
			pM->getRect(&moving_horizontal);
			pM->getRect(&moving_vertical);
			pM->getVelosity(vel_x, vel_y);

			// set temp rects for future positions of the movable object
			moving_horizontal.moveLeft(vel_x);
			moving_vertical.moveTop(vel_y);

			for (n = 0; n < m_collidables.size(); ++n)
			{
				pC = m_collidables[n];

				if (pC->isCollision(&moving_horizontal))
				{
					hasCollided = true;

					resolve_collision_horizontal<CMovable, CCollidable>(pM, vel_x, pC);
				}

				if (pC->isCollision(&moving_vertical))
				{
					hasCollided = true;

					resolve_collision_vertical<CMovable, CCollidable>(pM, vel_y, pC);
				}
			}

			// if the movable object's movement has not been manipulated by a collision,
			// have it step normally
			if (!hasCollided)
			{
				move_normally->push_front(pM);
			}
		}
	}


	void PhysicsEngine::n2_collision_gravity_static(std::list<CMovable*>* move_normally)
	{
		unsigned int i = 0, n = 0;
		TRect<int> moving_horizontal, moving_vertical;
		float vel_x, vel_y;
		bool hasCollided;
		CCollidable* pC 	= NULL;
		CGravityBased* pG 	= NULL;
		bool isBlocked_down;

		// iterate through gravity based objects
		for (i = 0; i < m_gravityBased.size(); ++i)
		{
			pG = m_gravityBased[i];


			//////////////////////////////////////////////////
			//
			// Updating blocked flags
			//
			/////////////////////////////////////////////////

			// reset block flags for all edges
			pG->setIsSideBlocked(false, false, false, false);
			// check if any side is blocked for this gravity based to any
			// static object
			for (n = 0; n < m_collidables.size(); ++n)
			{
				pC = m_collidables[n];
				pG->determine_sideBlocked(pC);
			}

			// if a block is found, then the respective velocity will be set to 0
			// before collision detection
			pG->getVelosity(vel_x, vel_y);
			fix_blockedVelosities<CGravityBased>(pG, vel_x, vel_y);

			// since this is a gravity based object, it needs to know whether or
			// not it is falling, which is saying if blocked
			// down == true, falling == false
			isBlocked_down = false;
			pG->getIsSideBlocked_down(isBlocked_down);
			if (isBlocked_down)
			{
				pG->setFalling(false);
			}
			else
			{
				pG->setFalling(true);
			}


			//////////////////////////////////////////////////
			//
			// Begin collision detection & resolution
			//
			/////////////////////////////////////////////////

			// submit this object to the physics manipulation function
			// that changes the velocities based on time falling
			apply_physics(pG);

			// reset relevant vars in prep for collision detection
			hasCollided = false;
			pG->getRect(&moving_horizontal);
			pG->getRect(&moving_vertical);
			pG->getVelosity(vel_x, vel_y);

			// set temp rects for future positions of the movable object
			moving_horizontal.moveLeft(vel_x);
			moving_vertical.moveTop(vel_y);

			for (n = 0; n < m_collidables.size(); ++n)
			{
				pC = m_collidables[n];

				if (pC->isCollision(&moving_horizontal))
				{
					hasCollided = true;

					resolve_collision_horizontal<CGravityBased, CCollidable>(pG, vel_x, pC);
				}

				if (pC->isCollision(&moving_vertical))
				{
					hasCollided = true;

					resolve_collision_vertical<CGravityBased, CCollidable>(pG, vel_y, pC);
				}
			}

			// if the movable object's movement has not been manipulated by a collision,
			// have it step normally
			if (!hasCollided)
			{
				move_normally->push_front(pG);
			}
		}
	}


	void PhysicsEngine::apply_moveNormally(std::list<CMovable*>* list) const
	{
		for (std::list<CMovable*>::iterator itr = list->begin();
		        itr != list->end();
		        ++itr)
		{
			(*itr)->move_normally();
		}
	}


	void PhysicsEngine::apply_physics(CGravityBased* g) const
	{
		if (g->isFalling())
		{
			// make game look nice
			// remember 'elapsed' is in MS, this reduces that massive x var
			double reductionFactor = 0.005;

			double elapsed = g->getMilliseconds();

			g->setVelosity_y(3.0f * (reductionFactor * elapsed));
		}
	}

} /* namespace engine */
