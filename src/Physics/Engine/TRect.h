#ifndef TRECT_H_
#define TRECT_H_

#include "../../Graphic/CSprite.h"
#include "../../include_sfml.h"

#include <assert.h>
#include <iostream>

namespace engine
{

	/**
	 * A template class for a Rectangle that the physics engine uses.
	 *
	 * Can be used to represent an Axis Aligned Bounding Box (AABB).
	 */
	template<class T>
	class TRect
	{
	public:
		/**
		 * Sets member variables at (0, 0, 100, 100)
		 */
		TRect();
		/**
		 * Creates a rect with given values.
		 */
		TRect(T left, T top, T width, T height);
		/**
		 * Copies the dominations from the given CSprite into this Rect
		 * DOES NOT keep the sprite around.
		 */
		TRect(CSprite* sprite);
		TRect(const TRect<T>& other);

		TRect& operator = (const TRect<T>& other);

		T getLeft() const;
		T getTop() const;
		T getWidth() const;
		T getHeight() const;
		void getAll(T& left, T& top, T& width, T& height) const;
		void getRect(TRect<int>* rect) const;
		void getPosition(T& left, T& top) const;
		void getCenter(T& x, T& y) const;

		void setLeft(T left);
		void setTop(T top);
		void setWidth(T width);
		void setHeight(T height);
		void setAll(T left, T top, T width, T height);
		/**
		 * Copies the dominations from the given CSprite into this Rect
		 * DOES NOT keep the sprite around.
		 */
		void setAll(CSprite* sprite);
		void setPosition(T left, T top);

		void moveLeft(T d_left);
		void moveTop(T d_top);
		void movePosition(T d_left, T d_top);

		void print() const;

		// TODO changeWidth && changeHeight
//		void changeWidth(T new_width);
//		void changeHeight(T new_height);

	private:
		T left;
		T top;
		T width;
		T height;
	};


	template<class T>
	inline TRect<T>::TRect()
	{
		setAll(0, 0, 100, 100);
	}

	template<class T>
	inline TRect<T>::TRect(T left, T top, T width, T height)
	{
		setAll(left, top, width, height);
	}

	template<class T>
	inline TRect<T>::TRect(CSprite* sprite)
	{
		// pull bounds out and cast it into this objects
		// type before setting
		sf::FloatRect temp_rect = sprite->getGlobalBounds();
		setAll((T) temp_rect.left, (T) temp_rect.top, (T) temp_rect.width, (T) temp_rect.height);
	}

	template<class T>
	inline TRect<T>::TRect(const TRect<T>& other)
	{
		T l, t, w, h;
		other.getAll(l, t, w, h);
		setAll(l, t, w, h);
	}

	template<class T>
	inline TRect<T>& TRect<T>::operator =(const TRect<T>& other)
	{
		if (this != &other)
		{
			T l, t, w, h;
			other.getAll(l, t, w, h);
			setAll(l, t, w, h);
		}

		return *this;
	}

	template<class T>
	inline T TRect<T>::getLeft() const
	{
		return left;
	}

	template<class T>
	inline T TRect<T>::getTop() const
	{
		return top;
	}

	template<class T>
	inline T TRect<T>::getWidth() const
	{
		return width;
	}

	template<class T>
	inline T TRect<T>::getHeight() const
	{
		return height;
	}

	template<class T>
	inline void TRect<T>::getAll(T& left, T& top, T& width, T& height) const
	{
		left = getLeft();
		top = getTop();
		width = getWidth();
		height = getHeight();
	}

	template<class T>
	inline void TRect<T>::getRect(TRect<int>* rect) const
	{
		rect->setAll(getLeft(), getTop(), getWidth(), getHeight());
	}

	template<class T>
	inline void TRect<T>::getPosition(T& left, T& top) const
	{
		left = getLeft();
		top = getTop();
	}

	template<class T>
	inline void TRect<T>::getCenter(T& x, T& y) const
	{
		x = left + (width / 2);
		y = top + (height / 2);
	}

	template<class T>
	inline void TRect<T>::setLeft(T left)
	{
		this->left = left;
	}

	template<class T>
	inline void TRect<T>::setTop(T top)
	{
		this->top = top;
	}

	template<class T>
	inline void TRect<T>::setWidth(T width)
	{
		this->width = width;
	}

	template<class T>
	inline void TRect<T>::setHeight(T height)
	{
		this->height = height;
	}

	template<class T>
	inline void TRect<T>::setAll(T left, T top, T width, T height)
	{
		setLeft(left);
		setTop(top);
		setWidth(width);
		setHeight(height);
	}

	template<class T>
	inline void TRect<T>::setAll(CSprite* sprite)
	{
		// pull bounds out and cast it into this objects
		// type before setting
		sf::FloatRect temp_rect = sprite->getGlobalBounds();
		setAll((T) temp_rect.left, (T) temp_rect.top, (T) temp_rect.width, (T) temp_rect.height);
	}

	template<class T>
	inline void TRect<T>::setPosition(T left, T top)
	{
		setLeft(left);
		setTop(top);
	}

	template<class T>
	inline void TRect<T>::moveLeft(T d_left)
	{
		left += d_left;
	}

	template<class T>
	inline void TRect<T>::moveTop(T d_top)
	{
		top += d_top;
	}

	template<class T>
	inline void TRect<T>::movePosition(T d_left, T d_top)
	{
		moveLeft(d_left);
		moveTop(d_top);
	}

	template<class T>
	inline void TRect<T>::print() const
	{
		using namespace std;

		cout << "pos:(" << getLeft() << ", " << getTop() << ", "
		     << getWidth() << ", " << getHeight() << ") ";
	}

} /* namespace engine */


#endif /* TRECT_H_ */
