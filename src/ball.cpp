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
		sf::Vector2f pos = rect.getPosition();

		// bounce on upper edges
		if (pos.y < 0)
		{
			vy *= -1;
			rect.setPosition(pos.x, 0);
		} else if(pos.y > 600 - HEIGHT) 
		{
			vy *= -1;
			rect.setPosition(pos.x, 600 - HEIGHT);
		}
		

		// right scored
		if (pos.x <= 0) {
			rect.setPosition(400, 300);
			scoreboard->scoreRight();
			reset(-1);
		}
		
		// left scored
		if (pos.x >= 800 - WIDTH) {
			rect.setPosition(400, 300);
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