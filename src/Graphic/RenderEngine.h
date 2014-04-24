#ifndef RENDERENGINE_H_
#define RENDERENGINE_H_

#include "CRenderable.h"

#include "../include_sfml.h"

#include <vector>

namespace engine
{

	class RenderEngine
	{
	public:
		RenderEngine(sf::RenderWindow* window);
		virtual ~RenderEngine();

		void addRenderable(CRenderable* r);

		void render();

		/**
		 * Used in sorting of the renderable objects based on their
		 * zorder value before rendering
		 */
		bool static compare(const CRenderable* lhs, const CRenderable* rhs);

	private:
		typedef std::vector<CRenderable*> RenderContainer;
		RenderContainer m_renderables;

		/**
		 * To increase efficiency on sorting of CRenderables,
		 * an 'old' size is kept, and if the current size changes
		 * they will differ, and the vector needs to be sorted.
		 *
		 * This variable is updated via the add*() functions,
		 * the constructor, and render() if it differs.
		 */
		unsigned int m_vectorSize;

		/**
		 * The place where everything will be rendered.
		 *
		 * This object does not have responsibility over this pointer.
		 */
		sf::RenderWindow* m_pWindow;
	};

} /* namespace engine */

#endif /* RENDERENGINE_H_ */
