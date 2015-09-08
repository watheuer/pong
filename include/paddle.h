#include <SFML/Graphics.hpp>

namespace pong {
	class Paddle
	{
	private:
		sf::RectangleShape rect;
		static const int SPEED = 500;
		static const int HEIGHT = 50;
		static const int WIDTH = 10;

	public:
		Paddle(float startX, float startY);
		sf::RectangleShape getRect() { return rect; }
		void moveUp(float delta);
		void moveDown(float delta);
	};
}
