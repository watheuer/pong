#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"

int main(int argc, char** argv)
{
	sf::Clock clock;
	float elapsed;
	pong::Paddle paddle(30, 30);
	pong::Ball ball(400, 300);

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

		elapsed = clock.restart().asSeconds();

		// check for keyboard input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			paddle.moveUp(elapsed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			paddle.moveDown(elapsed);
		}

		// update ball
		ball.update(elapsed);
		if (ball.getRect().getGlobalBounds().intersects(paddle.getRect().getGlobalBounds())) {
			ball.hit();
		}

		// clear screen
		window.clear();
		window.draw(paddle.getRect());
		window.draw(ball.getRect());

		// display
		window.display();
	}

	// Done.
	return 0;
}
