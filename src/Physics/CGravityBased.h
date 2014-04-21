#ifndef CGRAVITYBASED_H_
#define CGRAVITYBASED_H_

#include "CMovable.h"
#include "../include_sfml.h"

#include <stdint.h>

namespace engine
{

	class CGravityBased: public CMovable
	{
	public:
		CGravityBased(CSprite* sprite);
		virtual ~CGravityBased();

		float getSeconds() const;
		int32_t getMilliseconds() const;
		int64_t getMicroseconds() const;
		void restartGravityClock();

		bool isFalling() const;
		void setFalling(bool isFalling);

		virtual void collision_active(CCollidable* c);
		virtual void collision_active(CMovable* m);
		virtual void collision_active(CGravityBased* g);

		virtual void print() const;

	protected:
		sf::Clock m_gravityTimer;
		bool m_falling;

	private:
		bool isFirstUpdate;
	};

} /* namespace engine */

#endif /* CGRAVITYBASED_H_ */
