#include "ball.hpp"

namespace pong {
	Ball::Ball(float startX, float startY)
	{
		rect = sf::RectangleShape(sf::Vector2f(width, height));
		rect.setPosition(startX, startY);

		// test values
		vy = INIT_VY;
		vx = INIT_VX;
	}

	void Ball::update(float delta) 
	{
		sf::Vector2f pos = rect.getPosition();

		// bounce on upper edges
		if (pos.y <= 0 || pos.y >= 600 - height) vy *= -1;

		// right scored
		if (pos.x <= 0) {
			rect.setPosition(400, 300);
			reset();
		}
		
		// left scored
		if (pos.x >= 800 - width) {
			rect.setPosition(400, 300);
			reset();
		}

		rect.move(vx*delta, -vy*delta);
	}
	
	void Ball::reset()
	{
		vy = INIT_VY;
		vx = INIT_VX;
	}
	
	float Ball::random(float min, float max)
	{
		return ((float(rand()) / float(RAND_MAX)) * (max - min) + min);
	}
	
	void Ball::render(sf::RenderWindow* window)
	{
		window->draw(rect);
	}

	void Ball::hit()
	{
		vx *= -1.02;
		vy += random(-50, 50);
	}
}