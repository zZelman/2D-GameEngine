#include "../CSprite.h"
#include "../../include_sfml.h"
#include <assert.h>


namespace engine
{

	CSprite::CSprite(CTexture* pTexture,
	                 const sf::Vector2<int>& currSub)
	{
		m_pTexture = pTexture;

		setTexture(*m_pTexture);

		m_currSub = currSub;
		setSubImage(&currSub);
		chooseSubImage();
	}


	CSprite::~CSprite()
	{
	}


	CSprite::CSprite(const CSprite& other) : Sprite(other)
	{
		// [QUESTION] if a pointer is managed externally, do you need to allocate
		//		a 'new' in a copy constructor/copy assignment?

		m_pTexture = other.m_pTexture; // managed externally
	}


	void CSprite::setSubImage(int col, int row)
	{
#ifdef DEBUG
		assert(col <= m_pTexture->getSubNum().x && col > 0);
		assert(row <= m_pTexture->getSubNum().y && row > 0);
#endif
		m_currSub.x = col;
		m_currSub.y = row;

		chooseSubImage();
	}


	void CSprite::setSubImage(const sf::Vector2<int>* newSub)
	{
		int col = newSub->x;
		int row = newSub->y;

#ifdef DEBUG
		assert(col <= m_pTexture->getSubNum().x && col > 0);

		assert(row <= m_pTexture->getSubNum().y && row > 0);
#endif
		m_currSub.x = col;
		m_currSub.y = row;

		chooseSubImage();
	}


	const sf::Vector2<int>& CSprite::getSubNum() const
	{
		return m_pTexture->getSubNum();
	}


	void CSprite::chooseSubImage()
	{
		// selects a sub-section of the texture
		int w = m_pTexture->getSubSize().x;
		int h = m_pTexture->getSubSize().y;
		int topX = w * (m_currSub.x - 1);
		int topY = h * (m_currSub.y - 1);
		setTextureRect(sf::IntRect(topX, topY, w, h));
	}


}  // namespace engine
