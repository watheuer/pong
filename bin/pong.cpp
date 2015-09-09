#include <SFML/Graphics.hpp>
#include <vector>
#include "ball.hpp"

int main(int argc, char** argv)
{
	sf::Clock clock;
	float elapsed;
	
	std::vector<pong::Entity*> entities;
	pong::Paddle paddle1(30, 250, 500);
	pong::Paddle paddle2(760, 250, 300);
	pong::Scoreboard scoreboard(10);
	pong::Ball ball(400, 300, &scoreboard);

	// add to entities list
	entities.push_back(&paddle1);
	entities.push_back(&paddle2);
	entities.push_back(&ball);

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

		// check for keyboard input
		paddle1.moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		paddle1.moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		
		// follow behavior for second paddle
		if (ball.getY() + ball.getHeight()/2 < paddle2.getY() + paddle2.getHeight()/2)
		{
			paddle2.moveUp = true;
			paddle2.moveDown = false;
		}
		else
		{
			paddle2.moveDown = true;
			paddle2.moveUp = false;
		}
			
		// check collision
		if (ball.getRect().getGlobalBounds().intersects(paddle1.getRect().getGlobalBounds()))
		{
			ball.hit(&paddle1, 1);
		}
		if (ball.getRect().getGlobalBounds().intersects(paddle2.getRect().getGlobalBounds()))
		{
			ball.hit(&paddle2, -1);
		}
		
		// update objects
		elapsed = clock.restart().asSeconds();
		for (unsigned i = 0; i < entities.size(); i++)
		{
			pong::Entity* e = entities[i];
			e->update(elapsed);
		}

		// draw entities
		window.clear();
		scoreboard.render(&window);
		for (unsigned i = 0; i < entities.size(); i++)
		{
			pong::Entity* e = entities[i];
			e->render(&window);
		}


		// display
		window.display();
	}

	return 0;
}