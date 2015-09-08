#include "paddle.h"

pong::Paddle::Paddle(float startX, float startY) 
{
	rect = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
	rect.setPosition(startX, startY);
}

void pong::Paddle::moveUp(float delta) 
{
	// don't let rect leave screen
	if (rect.getPosition().y > 0) {
		rect.move(0, -SPEED * delta);
	}
}

void pong::Paddle::moveDown(float delta)
{
	// don't let rect leave screen
	if (rect.getPosition().y < 600 - HEIGHT){
		rect.move(0, SPEED * delta);
	}
}