#ifndef CCOLLIDABLE_H_
#define CCOLLIDABLE_H_

#include "TRect.h"

namespace engine
{

	/**
	 * The base class for all physics objects.
	 *
	 * Objects who inherit from this can collide with other CCollidable objects
	 */
	class CCollidable
	{
	public:
		CCollidable(CSprite* sprite);
		CCollidable(const TRect<int>* rect);
		virtual ~CCollidable();

		int getLeft() const;
		int getTop() const;
		int getWidth() const;
		int getHeight() const;
		void getAll(int& left, int& top, int& width, int& height) const;
		void getRect(TRect<int>* rect) const;
		void getPosition(int& left, int& top) const;
		void getCenter(int& x, int& y) const;

		virtual void print() const;

		/**
		 * Does 'this' and 'other_rect' intersect?
		 */
		bool isCollision(const TRect<int>* other_rect) const;

		virtual void collision_active();
		virtual void collision_passive();

	protected:
		/**
		 * Axis Aligned Bounding Box (AABB), the thing that is the defined
		 * region of this object.
		 */
		TRect<int> m_aabb;
	};

} /* namespace engine */

#endif /* CCOLLIDABLE_H_ */
