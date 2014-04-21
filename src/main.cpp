#include "include_sfml.h"
#include "Graphic/CTexture.h"
#include "Graphic/CSprite.h"
#include "GameElement_movable.h"
#include "GameElement_static.h"
#include "GameElement_gravity.h"
#include "Physics/PhysicsEngine.h"

#include <iostream>

sf::RenderWindow* g_window;
CTexture* g_texture;

CSprite* g_sprite_gravity;
GameElement_gravity* g_element_gravity;

CSprite* g_sprite_movable;
GameElement_movable* g_element_movable;

CSprite* g_sprite_static_1;
GameElement_static* g_element_static_1;
CSprite* g_sprite_static_2;
GameElement_static* g_element_static_2;

engine::PhysicsEngine* g_physicsEngine;

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
				g_element_gravity->setVelosity_y(-5);
				break;
			case sf::Keyboard::A:
				g_element_gravity->setVelosity_x(-5);
				break;
			case sf::Keyboard::S:
				g_element_gravity->setVelosity_y(5);
				break;
			case sf::Keyboard::D:
				g_element_gravity->setVelosity_x(5);
				break;

			default:
				break;
			}
			break;

		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				g_element_gravity->setVelosity_y(0);
				break;
			case sf::Keyboard::A:
				g_element_gravity->setVelosity_x(0);
				break;
			case sf::Keyboard::S:
				g_element_gravity->setVelosity_y(0);
				break;
			case sf::Keyboard::D:
				g_element_gravity->setVelosity_x(0);
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
	g_physicsEngine->update();
}


/**
 * Simplistic rendering.
 */
void render_elements()
{
	g_window->clear(sf::Color::White);

	g_element_static_1->render();
	g_element_static_2->render();
//	g_element_movable->render();
	g_element_gravity->render();

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
	g_texture = new CTexture("res/Players/letter debug(32x32, 2x2).png",
	                         sf::Vector2<int>(32, 32),
	                         sf::Vector2<int>(2, 2));

	// gravity
	g_sprite_gravity = new CSprite(g_texture, sf::Vector2<int>(1, 2));
	g_sprite_gravity->setPosition(0, 0);
	g_element_gravity = new GameElement_gravity(g_sprite_gravity, g_window);

	// movable
	g_sprite_movable = new CSprite(g_texture, sf::Vector2<int>(2, 1));
	g_sprite_movable->setPosition(0, 0);
	g_element_movable = new GameElement_movable(g_sprite_movable, g_window);

	// static 1
	g_sprite_static_1 = new CSprite(g_texture, sf::Vector2<int>(1, 1));
	g_sprite_static_1->setPosition(10 + 0, 32 * 5);
	g_element_static_1 = new GameElement_static(g_sprite_static_1, g_window);

	// static 2
	g_sprite_static_2 = new CSprite(g_texture, sf::Vector2<int>(1, 1));
	g_sprite_static_2->setPosition(10 + 32, 32 * 5);
	g_element_static_2 = new GameElement_static(g_sprite_static_2, g_window);

	// physics engine
	g_physicsEngine = new engine::PhysicsEngine();
	g_physicsEngine->addCollidable(g_element_static_1);
	g_physicsEngine->addCollidable(g_element_static_2);
	g_physicsEngine->addMovable(g_element_movable);
	g_physicsEngine->addGravityBased(g_element_gravity);
}


/**
 * Delete unit testing objects.
 */
void delete_elements()
{
	delete g_physicsEngine;

	delete g_sprite_gravity;
	delete g_element_gravity;

	delete g_element_static_2;
	delete g_sprite_static_2;

	delete g_element_static_1;
	delete g_sprite_static_1;

	delete g_element_movable;
	delete g_sprite_movable;

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
