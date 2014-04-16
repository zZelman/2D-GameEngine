#ifndef TRECT_H_
#define TRECT_H_

namespace engine
{

	/**
	 * A template class for a Rectangle that the physics engine uses.
	 */
	template<class T>
	class TRect
	{
	public:
		TRect();
		TRect(const TRect<T>& other);
		~TRect();

		TRect& operator = (const TRect<T>& other);

		T getLeft() const;
		T getTop() const;
		T getWidth() const;
		T getHeight() const;
		void getAll(T& left, T& top, T& width, T& height) const;
		void getCenter(T& x, T& y) const;

		void setLeft(T left);
		void setTop(T top);
		void setWidth(T width);
		void setHeight(T height);
		void setAll(T left, T top, T width, T height);

	private:
		T left;
		T top;
		T width;
		T height;
	};

} /* namespace engine */

#endif /* TRECT_H_ */
