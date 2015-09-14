#include <SFML/Graphics.hpp>

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "entity.hpp"
#endif

namespace pong 
{
	class Paddle : public Entity
	{
	private:
		float speed;
		static const int HEIGHT = 80;
		static const int WIDTH = 10;
		static const int INIT_Y = 250;
		
	public:
		Paddle(float startX, float speed);
		
		void update(float delta);
		bool moveUp;
		bool moveDown;
		void render(sf::RenderWindow* window);
		void reset();
		void setSpeed(float s) { speed = s; }
		
		const int getHeight() { return HEIGHT; }
		const int getWidth() { return WIDTH; }
		float getVelocity() { return vy; }
	};
}
