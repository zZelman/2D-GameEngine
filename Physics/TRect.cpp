#include "TRect.h"

namespace engine
{

	template<class T>
	TRect<T>::TRect()
	{
	}

	template<class T>
	TRect<T>::TRect(const TRect<T>& other)
	{
		T left, top, widht, height;
		other.getAll(left, top, width, height);
		setAll(left, top, width, height);
	}

	template<class T>
	TRect<T>::~TRect()
	{
		// nothing to do
	}

	template<class T>
	TRect& TRect<T>::operator =(const TRect<T>& other)
	{
		if (this != &other)
		{
			T left, top, widht, height;
			other.getAll(left, top, width, height);
			setAll(left, top, width, height);
		}

		return *this;
	}

	template<class T>
	T TRect<T>::getLeft() const
	{
		return left;
	}

	template<class T>
	T TRect<T>::getTop() const
	{
		return top;
	}

	template<class T>
	T TRect<T>::getWidth() const
	{
		return width;
	}

	template<class T>
	T TRect<T>::getHeight() const
	{
		return height;
	}

	template<class T>
	void TRect<T>::getAll(T& left, T& top, T& width, T& height) const
	{
		left = getLeft();
		top = getTop();
		width = getWidth();
		height = getHeight();
	}

	template<class T>
	void TRect<T>::getCenter(T& x, T& y) const
	{
		x = left + (width / 2);
		y = top + (height / 2);
	}

	template<class T>
	void TRect<T>::setLeft(T left)
	{
		this->left = left;
	}

	template<class T>
	void TRect<T>::setTop(T top)
	{
		this->top = top;
	}

	template<class T>
	void TRect<T>::setWidth(T width)
	{
		this->width = width;
	}

	template<class T>
	void TRect<T>::setHeight(T height)
	{
		this->height = height;
	}

	template<class T>
	void TRect<T>::setAll(T left, T top, T width, T height)
	{
		setLeft(left);
		setTop(top);
		setWidth(width);
		setHeight(height);
	}
} /* namespace engine */
