#ifndef CMOVABLE_H_
#define CMOVABLE_H_

#include "CCollidable.h"

namespace engine
{

	/**
	 * A plane-old-data-structure to tell whether the directions
	 * are "physically" blocked for movement.
	 */
	struct SSideBlocked
	{
		bool left, right, up, down;
	};


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

		void getVelosity_x(float& x) const;
		void getVelosity_y(float& y) const;
		void getVelosity(float& x, float& y) const;

		void setVelosity_x(float x);
		void setVelosity_y(float y);
		void setVelosity(float x, float y);

		void getIsSideBlocked_left(bool& left) const;
		void getIsSideBlocked_right(bool& right) const;
		void getIsSideBlocked_up(bool& up) const;
		void getIsSideBlocked_down(bool& down) const;
		void getIsSideBlocked(SSideBlocked& s) const;
		void getIsSideBlocked(bool& left, bool& right, bool& up, bool& down) const;

		void setIsSideBlocked_left(bool left);
		void setIsSideBlocked_right(bool right);
		void setIsSideBlocked_up(bool up);
		void setIsSideBlocked_down(bool down);
		void setIsSideBlocked(SSideBlocked s);
		void setIsSideBlocked(bool left, bool right, bool up, bool down);

		//////////////////////////////////////////////
		//
		// End getters/setters, begin useful functions
		//
		//////////////////////////////////////////////

		/**
		 * Update position based on x and y velocities
		 */
		virtual void move_normally();

		/**
		 * Given the CCollidable object, does it block one of your sides?
		 */
		void determine_sideBlocked(CCollidable* c);

		virtual void print() const;

	protected:
		float velosity_x, velosity_y;

		/**
		 * Blocked == true.
		 */
		struct SSideBlocked isSideBlocked;

	private:
		/**
		 * This object does not have responsibility over the
		 * lifetime of this sprite
		 */
		CSprite* m_pSprite;
	};

} /* namespace engine */

#endif /* CMOVABLE_H_ */
