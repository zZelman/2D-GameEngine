#include "../CRenderable.h"

#include <iostream>

namespace engine
{


	CRenderable::CRenderable(CSprite* sprite, int zorder)
	{
		m_pSprite = sprite;
		m_zorder = zorder;
	}


	CRenderable::~CRenderable()
	{
	}


	const CSprite* CRenderable::getSprite() const
	{
		return m_pSprite;
	}


	int CRenderable::getZOrder() const
	{
		return m_zorder;
	}

	void CRenderable::update_render()
	{
	}


	void CRenderable::print() const
	{
		std::cout << "z:" << m_zorder << std::endl;
	}


} /* namespace engine */
