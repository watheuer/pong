#include "paddle.hpp"
#include <cmath>

namespace pong {
	Paddle::Paddle(float startX, float startY, float initSpeed):
	moveUp(false), moveDown(false)
	{
		rect = sf::RectangleShape(sf::Vector2f(width, height));
		rect.setPosition(startX, startY);
		
		speed = initSpeed;
	}
	
	void Paddle::update(float delta)
	{
		vy = speed;
		
		if (moveUp && rect.getPosition().y > 0)
		{
			rect.move(0, -vy * delta);
		} else if (moveDown && rect.getPosition().y < 600 - height)
		{
			rect.move(0, vy * delta);
		}
	}
	
	void Paddle::render(sf::RenderWindow* window)
	{
		window->draw(rect);
	}
}