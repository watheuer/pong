#include "paddle.h"

namespace pong {
	Paddle::Paddle(float startX, float startY)
	{
		rect = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
		rect.setPosition(startX, startY);
	}

	void Paddle::moveUp(float delta)
	{
		// don't let rect leave screen
		if (rect.getPosition().y > 0) {
			rect.move(0, -SPEED * delta);
		}
	}

	void Paddle::moveDown(float delta)
	{
		// don't let rect leave screen
		if (rect.getPosition().y < 600 - HEIGHT) {
			rect.move(0, SPEED * delta);
		}
	}
}