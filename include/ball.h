#include <SFML/Graphics.hpp>

namespace pong {
	class Ball
	{
	private:
		sf::RectangleShape rect;
		static const int HEIGHT = 10;
		static const int WIDTH = 10;
		float vy;
		float vx;

	public:
		Ball(float startX, float startY);
		sf::RectangleShape getRect() { return rect; }
		void update(float delta);
		void hit();
	};
}
