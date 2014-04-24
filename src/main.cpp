#include "include_sfml.h"
#include "Graphic/CTexture.h"
#include "Graphic/CSprite.h"
#include "Graphic/RenderEngine.h"

#include "Physics/PhysicsEngine.h"

#include "GameElement_movable.h"
#include "GameElement_static.h"
#include "GameElement_gravity.h"


#include <iostream>

sf::RenderWindow* g_window;
engine::CTexture* g_texture;

engine::CSprite* g_sprite_g;
GameElement_gravity* g_element_g;

engine::CSprite* g_sprite_m;
GameElement_movable* g_element_m_r;

engine::CSprite* g_sprite_s_1;
GameElement_static* g_element_s_1;
engine::CSprite* g_sprite_s_2;
GameElement_static* g_element_s_2;

engine::PhysicsEngine* g_physicsEngine;

engine::RenderEngine* g_renderEngine;

/**
 * Simplistic window event handling.
 */
void window_events(bool& done)
{
	sf::Event event;
	while (g_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			g_window->close();
			break;

			// keyboard
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				done = true;
				g_window->close();
				break;
			case sf::Keyboard::W:
				g_element_m_r->setVelosity_y(-5);
				break;
			case sf::Keyboard::A:
				g_element_m_r->setVelosity_x(-5);
				break;
			case sf::Keyboard::S:
				g_element_m_r->setVelosity_y(5);
				break;
			case sf::Keyboard::D:
				g_element_m_r->setVelosity_x(5);
				break;

			default:
				break;
			}
			break;

		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				g_element_m_r->setVelosity_y(0);
				break;
			case sf::Keyboard::A:
				g_element_m_r->setVelosity_x(0);
				break;
			case sf::Keyboard::S:
				g_element_m_r->setVelosity_y(0);
				break;
			case sf::Keyboard::D:
				g_element_m_r->setVelosity_x(0);
				break;
			default:
				break;
			}
			break;

			// mouse
		case sf::Event::MouseButtonPressed:
			{
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Right:
					break;
				case sf::Mouse::Left:
					break;
				default:
					break;
				}
				break;
			}

		default:
			break;
		}

	}
}

/**
 * Simplistic updating.
 */
void update_elements()
{
	g_physicsEngine->update_physics();
}


/**
 * Simplistic rendering.
 */
void render_elements()
{
	g_window->clear(sf::Color::White);

	g_element_s_1->render();
	g_element_s_2->render();
//	g_element_g->render();
	g_renderEngine->render();

	g_window->display();
}

/**
 * Init unit testing objects.
 */
void init_elements()
{
	// window
	g_window = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");

	// texture for sprites
	g_texture = new engine::CTexture("res/Players/letter debug(32x32, 2x2).png",
	                                 sf::Vector2<int>(32, 32),
	                                 sf::Vector2<int>(2, 2));

	// gravity
	g_sprite_g = new engine::CSprite(g_texture, sf::Vector2<int>(1, 2));
	g_sprite_g->setPosition(0, 0);
	g_element_g = new GameElement_gravity(g_sprite_g, g_window);

	// movable
	g_sprite_m = new engine::CSprite(g_texture, sf::Vector2<int>(2, 1));
	g_sprite_m->setPosition(0, 0);
	g_element_m_r = new GameElement_movable(g_sprite_m, 0);

	// static 1
	g_sprite_s_1 = new engine::CSprite(g_texture, sf::Vector2<int>(1, 1));
	g_sprite_s_1->setPosition(10 + 0, 32 * 5);
	g_element_s_1 = new GameElement_static(g_sprite_s_1, g_window);

	// static 2
	g_sprite_s_2 = new engine::CSprite(g_texture, sf::Vector2<int>(1, 1));
	g_sprite_s_2->setPosition(10 + 32, 32 * 5);
	g_element_s_2 = new GameElement_static(g_sprite_s_2, g_window);

	// physics engine
	g_physicsEngine = new engine::PhysicsEngine();
	g_physicsEngine->addCollidable(g_element_s_1);
	g_physicsEngine->addCollidable(g_element_s_2);
	g_physicsEngine->addMovable(g_element_m_r);
	g_physicsEngine->addGravityBased(g_element_g);

	// render enginge
	g_renderEngine = new engine::RenderEngine(g_window);
	g_renderEngine->addRenderable(g_element_m_r);
}


/**
 * Delete unit testing objects.
 */
void delete_elements()
{
	delete g_renderEngine;

	delete g_physicsEngine;

	delete g_sprite_g;
	delete g_element_g;

	delete g_element_s_2;
	delete g_sprite_s_2;

	delete g_element_s_1;
	delete g_sprite_s_1;

	delete g_element_m_r;
	delete g_sprite_m;

	delete g_texture;

	delete g_window;
}


/**
 * Start of program.
 */
int main(int argc, char* argv[])
{
	init_elements();

	g_window->setFramerateLimit(60);

	bool done = false;

	while (!done && g_window->isOpen())
	{
		window_events(done);
		update_elements();
		render_elements();
	}

	delete_elements();

	return 0;
}
