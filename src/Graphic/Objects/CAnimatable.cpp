#include "../CAnimatable.h"

namespace engine
{


	CAnimatable::CAnimatable(CSprite* sprite, int zorder, int32_t ms_animation)
		: CRenderable(sprite, zorder), m_subNum(sprite->getSubNum())
	{
		isFirstUpdate = true;

		shouldChangeRenderImage = false;
	}


	CAnimatable::~CAnimatable()
	{
	}


	void CAnimatable::update_render()
	{
		if (isFirstUpdate == true)
		{
			m_animationClock.restart();
			isFirstUpdate = false;
			return;
		}

		if (m_animationClock.getElapsedTime().asMilliseconds() > m_animationTimeStep)
		{
			shouldChangeRenderImage = true;
		}
	}

} /* namespace engine */
