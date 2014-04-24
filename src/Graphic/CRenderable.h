#ifndef CRENDERABLE_H_
#define CRENDERABLE_H_

#include "CSprite.h"

namespace engine
{

	class CRenderable
	{
	public:
		CRenderable(CSprite* sprite, int zorder);
		virtual ~CRenderable();

		const CSprite* getSprite() const;
		int getZOrder() const;

		virtual void update_render();

		virtual void print() const;

	protected:
		/**
		 * This object and all derivatives do not have
		 * responsibility over this pointer
		 */
		CSprite* m_pSprite;

		/**
		 * Used to sort, and render objects in a specific way.
		 *
		 * A value of 0 means on top of everything else.
		 */
		int m_zorder;
	};

} /* namespace engine */

#endif /* CRENDERABLE_H_ */
