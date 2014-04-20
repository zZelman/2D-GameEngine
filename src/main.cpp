#include "include_sfml.h"
#include "Graphic/CTexture.h"
#include "Graphic/CSprite.h"
#include "GameElement_movable.h"
#include "GameElement_static.h"
#include "Physics/PhysicsEngine.h"

sf::RenderWindow* g_window;
CTexture* g_texture;

CSprite* g_sprite_movable;
GameElement_movable* g_element_movable;

CSprite* g_sprite_static;
GameElement_static* g_element_static;

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
				g_element_movable->moveTop(-5);
				g_element_movable->print();
				break;
			case sf::Keyboard::A:
				g_element_movable->moveLeft(-5);
				g_element_movable->print();
				break;
			case sf::Keyboard::S:
				g_element_movable->moveTop(5);
				g_element_movable->print();
				break;
			case sf::Keyboard::D:
				g_element_movable->moveLeft(5);
				g_element_movable->print();
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

	g_element_static->render();
	g_element_movable->render();

	g_window->display();
}

/**
 * Init unit testing objects.
 */
void init_elements()
{
	g_window = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");

	g_texture = new CTexture("res/Players/arrow debug(32x32, 2x2).png",
	                         sf::Vector2<int>(32, 32),
	                         sf::Vector2<int>(2, 2));

	g_sprite_movable = new CSprite(g_texture, sf::Vector2<int>(1, 1));
	g_sprite_movable->setPosition(0, 0);
	g_element_movable = new GameElement_movable(g_sprite_movable, g_window);

	g_sprite_static = new CSprite(g_texture, sf::Vector2<int>(2, 1));
	g_sprite_static->setPosition(60, 60);
	g_element_static = new GameElement_static(g_sprite_static, g_window);

	g_physicsEngine = new engine::PhysicsEngine();
	g_physicsEngine->addCollidable(g_element_static);
	g_physicsEngine->addMovable(g_element_movable);
}


/**
 * Delete unit testing objects.
 */
void delete_elements()
{
	delete g_physicsEngine;

	delete g_element_static;
	delete g_sprite_static;

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
