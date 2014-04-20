#include "CMovable.h"

namespace engine
{


	CMovable::CMovable(CSprite* sprite)
		: CCollidable(sprite)
	{
		m_pSprite = sprite;
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


	// TODO changeWidth && changeHeight
//	void CMovable::changeWidth(int new_width) {
//		// set the arbitrary rectangle
//		m_aabb.changeWidth(new_width);
//
//
//		// set the sfml api rectangle
//		float f_width = (float) getWidth();
//		float f_width_prime = (float) new_width;
//
//		// Wx=W'
//		// x = W'/W
//		float factor = f_width / f_width_prime;
//
//		const sf::Vector2f scale = m_pSprite->getScale();
//		m_pSprite->setScale(factor, scale.y);
//	}
//
//
//	void CMovable::changeHeight(int new_height) {
//		// set the arbitrary rectangle
//		m_aabb.changeHeight(new_height);
//
//
//		// set the sfml api rectangle
//		float f_height = (float) getHeight();
//		float f_height_prime = (float) new_height;
//
//		// Hx=H'
//		// x = H'/H
//		float factor = f_height / f_height_prime;
//
//		const sf::Vector2f scale = m_pSprite->getScale();
//		m_pSprite->setScale(scale.x, factor);
//	}

} /* namespace engine */
