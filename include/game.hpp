#include <SFML/Graphics.hpp>
#include <vector>
#include "ball.hpp"

class Game
{
public:
	enum GameState
	{
		MENU,
		GAME,
		RESTART
	};
	void run();
	Game();
	
private:
	void update();
	void updateAI();
	void draw();
	void processInput();
	
	GameState gameState;
	sf::RenderWindow window;
	sf::Clock clock;
	
	std::vector<pong::Entity*> entities;
	pong::Paddle paddle1;
	pong::Paddle paddle2;
	pong::Scoreboard scoreboard;
	pong::Ball ball;
};