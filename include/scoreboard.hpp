#include <SFML/Graphics.hpp>

namespace pong 
{
	class Scoreboard
	{
	private:
		int leftScore;
		int rightScore;
		int maxScore;
		sf::Font font;
		sf::Text text1;
		sf::Text text2;
		
	public:
		Scoreboard(int max);
		void scoreLeft() { leftScore++; }
		void scoreRight() { rightScore++; }
		void render(sf::RenderWindow* window);
	};
}