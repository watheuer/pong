#include <SFML/Graphics.hpp>
#include "paddle.h"

int main(int argc, char** argv)
{
	sf::Clock clock;
	float elapsed;
	pong::Paddle paddle(30, 30);

	// create main window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Pong", sf::Style::Close);

	// start main loop
	while (window.isOpen())
	{
		// process events
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Exit
			if (Event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// game loop
		elapsed = clock.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			paddle.moveUp(elapsed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			paddle.moveDown(elapsed);
		}

		// clear screen
		window.clear();
		window.draw(paddle.getRect());

		// display
		window.display();
	}

	// Done.
	return 0;
}
