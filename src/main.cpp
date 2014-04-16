#include "include_sfml.h"

/**
 * Simplistic window event handling.
 */
void window_events(sf::RenderWindow& window, bool& done)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;

			// keyboard
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				done = true;
				window.close();
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

}


/**
 * Simplistic rendering.
 */
void render_elements(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);


	window.display();
}


/**
 * Start of program.
 */
int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setFramerateLimit(60);

	bool done = false;

	while (!done && window.isOpen())
	{
		window_events(window, done);
		update_elements();
		render_elements(window);
	}

	return 0;
}
