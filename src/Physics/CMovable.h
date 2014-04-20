#ifndef CMOVABLE_H_
#define CMOVABLE_H_

#include "CCollidable.h"

namespace engine
{

	class CMovable: public engine::CCollidable
	{
	public:
		CMovable(CSprite* sprite);
		virtual ~CMovable();

		void setLeft(int left);
		void setTop(int top);
		void setWidth(int width);
		void setHeight(int height);
		void setAll(int left, int top, int width, int height);
		void setPosition(int left, int top);

		void moveLeft(int d_left);
		void moveTop(int d_top);
		void movePosition(int d_left, int d_top);

		// TODO changeWidth && changeHeight
//		void changeWidth(int new_width);
//		void changeHeight(int new_height);
	private:
		/**
		 * This object does not have responsibility over the
		 * lifetime of this sprite
		 */
		CSprite* m_pSprite;
	};

} /* namespace engine */

#endif /* CMOVABLE_H_ */
