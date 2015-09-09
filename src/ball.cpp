#include "ball.hpp"
#include <math.h>

namespace pong 
{
	Ball::Ball(float startX, float startY, Scoreboard* scoreboard):
	scoreboard(scoreboard)
	{
		rect = sf::RectangleShape(sf::Vector2f(width, height));
		rect.setPosition(startX, startY);

		// test values
		speed = 600;
		vy = 300;
		vx = 300;
	}

	void Ball::update(float delta) 
	{
		sf::Vector2f pos = rect.getPosition();

		// bounce on upper edges
		if (pos.y <= 0 || pos.y >= 600 - height) vy *= -1;

		// right scored
		if (pos.x <= 0) {
			rect.setPosition(400, 300);
			scoreboard->scoreRight();
			reset(-1);
		}
		
		// left scored
		if (pos.x >= 800 - width) {
			rect.setPosition(400, 300);
			scoreboard->scoreLeft();
			reset(1);
		}

		rect.move(vx*delta, -vy*delta);
	}
	
	void Ball::reset(int direction)
	{
		vy = 300;
		vx = 300;
	}
	
	float Ball::random(float min, float max)
	{
		return ((float(rand()) / float(RAND_MAX)) * (max - min) + min);
	}
	
	void Ball::render(sf::RenderWindow* window)
	{
		window->draw(rect);
	}

	/* logic taken from http://gamedev.stackexchange.com/questions/4253/in-pong-how-do-you-calculate-the-balls-direction-when-it-bounces-off-the-paddl */
	void Ball::hit(Paddle* paddle, int direction)
	{
		float relativeY = ((paddle->getY() + (paddle->getHeight()/2)) - (this->getY() + this->getHeight()/2))
							/(paddle->getHeight()/2);
		float bounce = relativeY * MAXBOUNCE;
		
		vx = speed * cos(bounce) * direction;
		vy = speed * sin(bounce);
	}
}