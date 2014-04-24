#include "../RenderEngine.h"

#include "../CSprite.h"

namespace engine
{


	RenderEngine::RenderEngine(sf::RenderWindow* window)
	{
		m_vectorSize = m_renderables.size();

		m_pWindow = window;
	}


	RenderEngine::~RenderEngine()
	{
	}


	void RenderEngine::addRenderable(CRenderable* r)
	{
		m_renderables.push_back(r);

		m_vectorSize = m_renderables.size();
	}


	void RenderEngine::render()
	{
		// for explanation, see m_vectorSize documentation
		if (m_vectorSize != m_renderables.size())
		{
			std::sort(m_renderables.begin(),
			          m_renderables.end(),
			          RenderEngine::compare);
			m_vectorSize = m_renderables.size();
		}

		// rendering
		const CSprite* sprite = NULL;
		CRenderable* r;
		for (unsigned int i = 0;
		        i < m_renderables.size();
		        ++i)
		{
			r = m_renderables[i];
			r->update_render();

			sprite = r->getSprite();

			m_pWindow->draw(*sprite);
		}
	}


	bool RenderEngine::compare(const CRenderable* lhs, const CRenderable* rhs)
	{
		return lhs->getZOrder() < rhs->getZOrder();
	}

} /* namespace engine */
