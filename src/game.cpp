#include "game.hpp"

Game::Game():
gameState(GAME), 
paddle1(30, 250, 500),
paddle2(760, 250, 300),
scoreboard(10),
ball(&scoreboard),
window(sf::VideoMode(800, 600, 32), "Pong", sf::Style::Close)
{
	// add to entities list
	entities.push_back(&paddle1);
	entities.push_back(&paddle2);
	entities.push_back(&ball);
}

void Game::run()
{
	while(window.isOpen())
	{
		// update different components
		processInput();
		updateAI();
		update();
		draw();
		
		// display
		window.display();
	}
}

void Game::processInput() 
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
}

void Game::updateAI()
{
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
}

void Game::update()
{
	float elapsed;
	
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
}

void Game::draw()
{
	// draw entities
	window.clear();
	scoreboard.render(&window);
	for (unsigned i = 0; i < entities.size(); i++)
	{
		pong::Entity* e = entities[i];
		e->render(&window);
	}
}