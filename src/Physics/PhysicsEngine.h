#ifndef PHYSICSENGINE_H_
#define PHYSICSENGINE_H_

#include "CCollidable.h"
#include "CMovable.h"
#include "CGravityBased.h"

#include <vector>
#include <list>

namespace engine
{

	class PhysicsEngine
	{
	public:
		PhysicsEngine();
		virtual ~PhysicsEngine();

		void addCollidable(CCollidable* c);
		void addMovable(CMovable* m);
		void addGravityBased(CGravityBased* g);

		void update();

	private:
		std::vector<CCollidable*> m_collidables;
		std::vector<CMovable*> m_movables;
		std::vector<CGravityBased*> m_gravityBased;

		void n2_collision();
		void n2_collision_move_static(std::list<CMovable*>* move_normally);
		void n2_collision_gravity_static(std::list<CMovable*>* move_normally);

		template<typename T>
		inline void fix_blockedVelosities(T* obj, float vel_x, float vel_y)
		{
			struct SSideBlocked s;
			obj->getIsSideBlocked(s);

			if (vel_x > 0 && s.right) // moving right, and is blocked right
			{
				obj->setVelosity_x(0);
			}
			else if (vel_x < 0 && s.left) // moving left, and is blocked left
			{
				obj->setVelosity_x(0);
			}

			if (vel_y > 0 && s.down) // moving down, and is blocked down
			{
				obj->setVelosity_y(0);
			}
			else if (vel_y < 0 && s.up) // moving up, and is blocked up
			{
				obj->setVelosity_y(0);
			}
		}

		template<typename From, typename To>
		inline void resolve_collision_horizontal(From* from, float vel_x, To* to)
		{
			struct SSideBlocked s;
			from->getIsSideBlocked(s);

			if (vel_x > 0 && !s.right) // moving right, and is NOT blocked right
			{
				from->setLeft(to->getLeft() - from->getWidth());
			}
			else if (vel_x < 0 && !s.left) // moving left, and is NOT blocked left
			{
				from->setLeft(to->getLeft() + to->getWidth());
			}
		}

		template<typename From, typename To>
		inline void resolve_collision_vertical(From* from, float vel_y, To* to)
		{
			struct SSideBlocked s;
			from->getIsSideBlocked(s);

			if (vel_y > 0 && !s.down) // moving down, and is NOT blocked down
			{
				from->setTop(to->getTop() - from->getHeight());
			}
			else if (vel_y < 0 && !s.up) // moving up, and is NOT blocked up
			{
				from->setTop(to->getTop() + to->getHeight());
			}
		}

		void apply_moveNormally(std::list<CMovable*>* list) const;
		void apply_physics(CGravityBased* g) const;
	};

} /* namespace engine */

#endif /* PHYSICSENGINE_H_ */
