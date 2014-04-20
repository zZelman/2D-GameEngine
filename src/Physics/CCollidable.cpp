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
		m_aabb.print();
	}


	bool CCollidable::isCollision_horizontal(const TRect<int>* other_rect) const
	{
		// debug printing
//		this->print();
		other_rect->print();
		std::cout << std::endl;


		// general min/max variables for this and other
		int this_max, this_min, other_max, other_min;

		// x-axis
		this_min = getLeft();
		this_max = getLeft() + getWidth();
		other_min = other_rect->getLeft();
		other_max = other_rect->getLeft() + other_rect->getWidth();

		// right penetration
		if (this_min >= other_min && this_min <= other_max)
		{
			return true;
		}
		// left penetration
		if (other_min <= this_max && this_max <= other_max)
		{
			return true;
		}

		return false;
	}


	bool CCollidable::isCollision_vertical(const TRect<int>* other_rect) const
	{
		// debug printing
//		this->print();
//		other_rect->print();
//		std::cout << std::endl;


		// general min/max variables for this and other
		int this_max, this_min, other_max, other_min;

		// y-axis
		this_min = getTop();
		this_max = getTop() + getHeight();
		other_min = other_rect->getTop();
		other_max = other_rect->getTop() + other_rect->getHeight();

		// up penetration
		if (other_min <= this_min && this_min <= other_max)
		{
			return true;
		}
		// down penetration
		if (other_min <= this_max && this_max <= other_max)
		{
			return true;
		}

		return false;
	}


	bool CCollidable::isCollision(const TRect<int>* other_rect) const
	{
		// general min/max variables for this and other
		int this_max, this_min, other_max, other_min;

		// x-axis
		this_min = getLeft();
		this_max = getLeft() + getWidth();
		other_min = other_rect->getLeft();
		other_max = other_rect->getLeft() + other_rect->getWidth();
		if (this_max <= other_min || this_min >= other_max)
		{
			return false;
		}

		// y-axis
		this_min = getTop();
		this_max = getTop() + getHeight();
		other_min = other_rect->getTop();
		other_max = other_rect->getTop() + other_rect->getHeight();
		if (this_max <= other_min || this_min >= other_max)
		{
			return false;
		}

		// No separating axis found
		return true;
	}



	void CCollidable::collision_active()
	{
	}


	void CCollidable::collision_passive()
	{
	}

} /* namespace engine */
