#include "CCollidable.h"
#include "TRect.h"

#include <iostream>

namespace engine
{
	CCollidable::CCollidable(CSprite* sprite)
	{
		m_aabb.setAll(sprite);
	}


	CCollidable::CCollidable(const TRect<int>* rect)
	{
		m_aabb.setAll(rect->getLeft(), rect->getTop(),
		              rect->getWidth(), rect->getHeight());
	}


	CCollidable::~CCollidable()
	{
	}


	int CCollidable::getLeft() const
	{
		return m_aabb.getLeft();
	}


	int CCollidable::getTop() const
	{
		return m_aabb.getTop();
	}


	int CCollidable::getWidth() const
	{
		return m_aabb.getWidth();
	}


	int CCollidable::getHeight() const
	{
		return m_aabb.getHeight();
	}


	void CCollidable::getAll(int& left, int& top, int& width, int& height) const
	{
		left 	= getLeft();
		top 	= getTop();
		width 	= getWidth();
		height 	= getHeight();
	}


	void CCollidable::getRect(TRect<int>* rect) const
	{
		m_aabb.getRect(rect);
	}


	void CCollidable::getPosition(int& left, int& top) const
	{
		left 	= getLeft();
		top 	= getTop();
	}


	void CCollidable::getCenter(int& x, int& y) const
	{
		m_aabb.getCenter(x, y);
	}


	void CCollidable::print() const
	{
		using namespace std;

		cout << "(" << getLeft() << ", " << getTop() << ", "
		     << getWidth() << ", " << getHeight() << ")" << endl;
	}


	bool CCollidable::isCollision(const TRect<int>* other_rect) const
	{
		// general min/max variables for this and other
		int this_max, this_min, other_max, other_min;

		// X axis testing
		this_max = getLeft() + getWidth();
		this_min = getLeft();
		other_max = other_rect->getLeft() + other_rect->getWidth();
		other_min = other_rect->getLeft();
		if (this_max < other_min || this_min > other_max)
		{
			return false;
		}

		// Y axis testing
		this_max = getTop() + getHeight();
		this_min = getTop();
		other_max = other_rect->getTop() + other_rect->getHeight();
		other_min = other_rect->getTop();
		if (this_max < other_min || this_min > other_max)
		{
			return false;
		}

		// No seperating axis found
		// Therefore there is atleast one overlapping axis
		return true;
	}


	void CCollidable::collision_active()
	{
	}


	void CCollidable::collision_passive()
	{
	}

} /* namespace engine */
