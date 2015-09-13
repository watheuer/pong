#include "ball.hpp"
#include <ctime>
#include <cstdlib>
#include <cmath>

namespace pong 
{
	Ball::Ball(Scoreboard* scoreboard):
	scoreboard(scoreboard),
	speed(INIT_SPEED),
	MAXBOUNCE(1.047),
	INIT_ANGLE(0.7853)
	{
		rect = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
		rect.setPosition(INIT_X, INIT_Y);

		// init values, random initial angle based on maximum bounce
		vy = speed * std::cos(INIT_ANGLE);
		vx = speed * std::sin(INIT_ANGLE);
	}

	void Ball::update(float delta) 
	{
		// bounce on upper edges
		if (getY() < 0)
		{
			vy *= -1;
			rect.setPosition(getX(), 0);
		} else if(getY() > 600 - HEIGHT) 
		{
			vy *= -1;
			rect.setPosition(getX(), 600 - HEIGHT);
		}
		

		// right scored
		if (getX() <= 0) {
			scoreboard->scoreRight();
			reset(-1);
		}
		
		// left scored
		if (getX() >= 800 - WIDTH) {
			scoreboard->scoreLeft();
			reset(1);
		}

		rect.move(vx*delta, -vy*delta);
	}
	
	void Ball::reset(int direction)
	{
		speed = INIT_SPEED;
		rect.setPosition(INIT_X, INIT_Y);
		
		vx = speed * std::cos(INIT_ANGLE) * direction;
		vy = speed * std::sin(INIT_ANGLE);
	}
	
	void Ball::render(sf::RenderWindow* window)
	{
		window->draw(rect);
	}

	/* logic taken from http://gamedev.stackexchange.com/questions/4253/in-pong-how-do-you-calculate-the-balls-direction-when-it-bounces-off-the-paddl */
	void Ball::hit(Paddle* paddle, int direction)
	{	
		// get position relative to paddle	
		float relativeY = ((paddle->getY() + (paddle->getHeight()/2)) - (getY() + HEIGHT/2))
							/(paddle->getHeight()/2);
		float bounce = relativeY * MAXBOUNCE;
		
		// new vx and vy based on new bounce angle
		vx = speed * std::cos(bounce) * direction;
		vy = speed * std::sin(bounce);	
		
		// increase speed at every hit
		speed += 15;
	}
}