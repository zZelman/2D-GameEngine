#include "CMovable.h"

#include <iostream>

namespace engine
{


	CMovable::CMovable(CSprite* sprite)
		: CCollidable(sprite)
	{
		m_pSprite = sprite;
		setVelosity(0, 0);

		setIsSideBlocked(false, false, false, false);
	}


	CMovable::~CMovable()
	{
	}


	void CMovable::setLeft(int left)
	{
		// set the arbitrary rectangle
		m_aabb.setLeft(left);


		// set the sfml api rectangle
		m_pSprite->setPosition(left, getTop());
	}


	void CMovable::setTop(int top)
	{
		// set the arbitrary rectangle
		m_aabb.setTop(top);


		// set the sfml api rectangle
		m_pSprite->setPosition(getLeft(), top);
	}


	void CMovable::setWidth(int width)
	{
		// set the arbitrary rectangle
		m_aabb.setWidth(width);
	}


	void CMovable::setHeight(int height)
	{
		// set the arbitrary rectangle
		m_aabb.setHeight(height);
	}


	void CMovable::setAll(int left, int top, int width, int height)
	{
		setLeft(left);
		setTop(top);
		setWidth(width);
		setHeight(height);
	}


	void CMovable::setPosition(int left, int top)
	{
		setLeft(left);
		setTop(top);
	}


	void CMovable::moveLeft(int d_left)
	{
		// set the arbitrary rectangle
		m_aabb.moveLeft(d_left);


		// set the sfml api rectangle
		m_pSprite->move(d_left, 0);
	}


	void CMovable::moveTop(int d_top)
	{
		// set the arbitrary rectangle
		m_aabb.moveTop(d_top);


		// set the sfml api rectangle
		m_pSprite->move(0, d_top);
	}


	void CMovable::movePosition(int d_left, int d_top)
	{
		moveLeft(d_left);
		moveTop(d_top);
	}


	void CMovable::getVelosity_x(float& x) const
	{
		x = velosity_x;
	}


	void CMovable::getVelosity_y(float& y) const
	{
		y = velosity_y;
	}


	void CMovable::getVelosity(float& x, float& y) const
	{
		getVelosity_x(x);
		getVelosity_y(y);
	}


	void CMovable::setVelosity_x(float x)
	{
		velosity_x = x;
	}


	void CMovable::setVelosity_y(float y)
	{
		velosity_y = y;
	}


	void CMovable::setVelosity(float x, float y)
	{
		setVelosity_x(x);
		setVelosity_y(y);
	}


	void CMovable::getIsSideBlocked_left(bool& left) const
	{
		left = isSideBlocked.left;
	}


	void CMovable::getIsSideBlocked_right(bool& right) const
	{
		right = isSideBlocked.right;
	}


	void CMovable::getIsSideBlocked_up(bool& up) const
	{
		up = isSideBlocked.up;
	}


	void CMovable::getIsSideBlocked_down(bool& down) const
	{
		down = isSideBlocked.down;
	}


	void CMovable::getIsSideBlocked(SSideBlocked& s) const
	{
		getIsSideBlocked_left(s.left);
		getIsSideBlocked_right(s.right);
		getIsSideBlocked_up(s.up);
		getIsSideBlocked_down(s.down);
	}

	void CMovable::getIsSideBlocked(bool& left, bool& right, bool& up, bool& down) const
	{
		getIsSideBlocked_left(left);
		getIsSideBlocked_right(right);
		getIsSideBlocked_up(up);
		getIsSideBlocked_down(down);
	}


	void CMovable::setIsSideBlocked_left(bool left)
	{
		isSideBlocked.left = left;
	}


	void CMovable::setIsSideBlocked_right(bool right)
	{
		isSideBlocked.right = right;
	}


	void CMovable::setIsSideBlocked_up(bool up)
	{
		isSideBlocked.up = up;
	}


	void CMovable::setIsSideBlocked_down(bool down)
	{
		isSideBlocked.down = down;
	}


	void CMovable::setIsSideBlocked(SSideBlocked s)
	{
		setIsSideBlocked_left(s.left);
		setIsSideBlocked_right(s.right);
		setIsSideBlocked_up(s.up);
		setIsSideBlocked_down(s.down);
	}


	void CMovable::setIsSideBlocked(bool left, bool right, bool up, bool down)
	{
		setIsSideBlocked_left(left);
		setIsSideBlocked_right(right);
		setIsSideBlocked_up(up);
		setIsSideBlocked_down(down);
	}


	void CMovable::move_normally()
	{
		movePosition(velosity_x, velosity_y);
	}


	void CMovable::determine_sideBlocked(CCollidable* c)
	{
		int blocking_size = 1;
		TRect<int> left, right, up, down;

		getRect(&left);
		getRect(&right);
		getRect(&up);
		getRect(&down);

		left.moveLeft(-blocking_size);
		right.moveLeft(blocking_size);
		up.moveTop(-blocking_size);
		down.moveTop(blocking_size);

		if (c->isCollision(&left))
		{
			isSideBlocked.left = true;
		}
		if (c->isCollision(&right))
		{
			isSideBlocked.right = true;
		}

		if (c->isCollision(&up))
		{
			isSideBlocked.up = true;
		}
		if (c->isCollision(&down))
		{
			isSideBlocked.down = true;
		}
	}

	void CMovable::print() const
	{
//		CCollidable::print();

		std::cout << "vel:[" << velosity_x << ", " << velosity_y << "] ";

		std::cout << "block:{" << isSideBlocked.left << ", " << isSideBlocked.right <<
		          ", " << isSideBlocked.up << ", " << isSideBlocked.down << "} ";
	}

} /* namespace engine */
