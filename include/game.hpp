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
	void newGame();
	Game();
	
private:
	void update();
	void updateAI();
	void draw();
	void processInput();
	void drawRestart();
	
	GameState gameState;
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Font font;
	sf::Text text;
	
	std::vector<pong::Entity*> entities;
	pong::Paddle paddle1;
	pong::Paddle paddle2;
	pong::Scoreboard scoreboard;
	pong::Ball ball;
};