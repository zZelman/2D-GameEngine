#ifndef PHYSICSENGINE_H_
#define PHYSICSENGINE_H_

#include "CCollidable.h"
#include "CMovable.h"

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

		void update();

	private:
		std::vector<CCollidable*> m_collidables;
		std::vector<CMovable*> m_movables;

		void n2_collision();
		void applyMoveNormally(std::list<CMovable*>* list) const;

		void resolve_collision(CMovable* m, float vel_x, float vel_y, CCollidable* c) const;
	};

} /* namespace engine */

#endif /* PHYSICSENGINE_H_ */
