#include "game.hpp"

Game::Game():
gameState(GAME), 
paddle1(30, 500),
paddle2(760, 300),
scoreboard(10),
ball(&scoreboard),
window(sf::VideoMode(800, 600, 32), "Pong", sf::Style::Close)
{	
	// add to entities list
	entities.push_back(&paddle1);
	entities.push_back(&paddle2);
	entities.push_back(&ball);

	font.loadFromFile("Roboto-Regular.ttf");
	text.setFont(font);
	text.setStyle(sf::Text::Regular);
	text.setCharacterSize(60);
	text.setColor(sf::Color::White);
}

void Game::newGame()
{
	gameState = GAME;
	paddle1.reset();
	paddle2.reset();
	scoreboard.reset();
}

void Game::run()
{
	while(window.isOpen())
	{
		processInput();
		
		// update different components
		switch (gameState)
		{
			case GAME:
				updateAI();
				update();
				draw();
				break;
			case RESTART:
				drawRestart();
				break;
		}
		
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
	
	if (gameState == RESTART && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		newGame();
	}
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
	
	// check for win 
	if (scoreboard.leftWin) 
	{
		gameState = RESTART;
		text.setString("You win!");
		text.setPosition(50, 50);
	}
	if (scoreboard.rightWin)
	{
		gameState = RESTART;
		text.setString("You lose!");
		text.setPosition(50, 50);
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

void Game::drawRestart()
{
	window.clear();
	window.draw(text);
}