#include "ball.hpp"
#include <ctime>
#include <cstdlib>
#include <cmath>

namespace pong 
{
	Ball::Ball(Scoreboard* scoreboard):
	scoreboard(scoreboard),
	speed(INIT_SPEED),
	MAXBOUNCE(1.047), // up to 60 degrees
	INIT_ANGLE(0.785), // 45 degrees
	VARIATION(0.175) // 10 degrees
	{
		rect = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
		rect.setPosition(INIT_X, INIT_Y);

		// init values, random initial angle based on maximum bounce
		vy = speed * std::cos(INIT_ANGLE);
		vx = speed * std::sin(INIT_ANGLE);
		
		// setup sounds
		sideBuffer.loadFromFile("side.wav");
		sideSound.setBuffer(sideBuffer);
		
		paddleBuffer.loadFromFile("paddle.wav");
		paddleSound.setBuffer(paddleBuffer);
		
		scoreBuffer.loadFromFile("score.wav");
		scoreSound.setBuffer(scoreBuffer);
	}

	void Ball::update(float delta) 
	{
		// bounce on upper edges
		if (getY() < 0)
		{
			// get new angle, add random element (VARIATION)
			float newAngle = std::atan2(-vy, vx);
			newAngle += ((float) rand() / RAND_MAX) * VARIATION - VARIATION/2;
			
			// set new vx, vy values
			vx = speed * std::cos(newAngle);
			vy = speed * std::sin(newAngle);
			
			rect.setPosition(getX(), 0);
			sideSound.play();
		} 
		else if(getY() > 600 - HEIGHT) 
		{
			// get new angle, add random element
			float newAngle = std::atan2(-vy, vx);
			newAngle += ((float) rand() / RAND_MAX) * VARIATION - VARIATION/2;
			
			// set new vx, vy values
			vx = speed * std::cos(newAngle);
			vy = speed * std::sin(newAngle);
			
			rect.setPosition(getX(), 600 - HEIGHT);
			sideSound.play();
		}
		
		// right scored
		if (getX() <= 0) {
			reset(-1);
			scoreboard->scoreRight();
		}
		
		// left scored
		if (getX() >= 800 - WIDTH) {
			reset(1);
			scoreboard->scoreLeft();
		}

		rect.move(vx*delta, -vy*delta);
	}
	
	void Ball::reset(int direction)
	{
		// play score sound
		scoreSound.play();
		
		// reset values
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
		
		// play sound
		paddleSound.play();
	}
}