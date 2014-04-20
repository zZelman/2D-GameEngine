#ifndef PHYSICSENGINE_H_
#define PHYSICSENGINE_H_

#include "CCollidable.h"
#include "CMovable.h"

#include <vector>

namespace engine
{

	class PhysicsEngine
	{
	public:
		PhysicsEngine();
		virtual ~PhysicsEngine();

		void addCollidable(CCollidable* c);
		void addMovable(CMovable* m);

		void update();

	private:
		std::vector<CCollidable*> m_collidables;
		std::vector<CMovable*> m_movables;

		void n2_collision();

		void resolve_move_collide(CMovable* m, CCollidable* c);
	};

} /* namespace engine */

#endif /* PHYSICSENGINE_H_ */
