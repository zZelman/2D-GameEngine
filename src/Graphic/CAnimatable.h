#ifndef CANIMATABLE_H_
#define CANIMATABLE_H_

#include "CRenderable.h"
#include "CSprite.h"

#include "../include_sfml.h"

#include <cstdint>

namespace engine
{

	class CAnimatable: public CRenderable
	{
	public:
		CAnimatable(CSprite* sprite, int zorder, int32_t ms_animation);
		virtual ~CAnimatable();

		virtual void update_render();

	protected:
		/**
		 * Time step to change render images.
		 */
		int32_t m_animationTimeStep;

		/**
		 * The clock keeping track of how long each render image is displayed.
		 */
		sf::Clock m_animationClock;

		/**
		 * A preventative boolean wrapped around the first render to
		 * prevent skipping.
		 */
		bool isFirstUpdate;

		/**
		 * A variable that sub classes check on to see if they should
		 * change the image being rendered.
		 *
		 * Sub classes should override update_render() and call it before
		 * checking on this variable.
		 */
		bool shouldChangeRenderImage;

		/**
		 * The LENGTH (cols, rows) on the texture the sprite refers to.
		 *
		 * It was pulled out of the sprite at this object initialization.
		 */
		const sf::Vector2<int>& m_subNum;

	};

} /* namespace engine */

#endif /* CANIMATABLE_H_ */
