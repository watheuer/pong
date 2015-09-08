#include "ball.h"

namespace pong {
	Ball::Ball(float startX, float startY)
	{
		rect = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
		rect.setPosition(startX, startY);

		// test values
		vy = 400;
		vx = 400;
	}

	void Ball::update(float delta) {
		sf::Vector2f pos = rect.getPosition();

		// bounce on upper edges
		if (pos.y <= 0 || pos.y >= 600 - HEIGHT) vy *= -1;

		// right scored
		if (pos.x <= 0) {
			rect.setPosition(400, 300);
			vx *= -1;
		}
		
		// left scored
		if (pos.x >= 800 - WIDTH) {
			rect.setPosition(400, 300);
			vx *= -1;
		}

		rect.move(vx*delta, -vy*delta);
	}

	void Ball::hit() {
		vx *= -1;
	}
}