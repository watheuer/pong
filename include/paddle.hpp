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
		
	public:
		Paddle(float startX, float startY, float speed);
		
		void update(float delta);
		bool moveUp;
		bool moveDown;
		void render(sf::RenderWindow* window);
		
		const int getHeight() { return HEIGHT; }
		const int getWidth() { return WIDTH; }
		float getVelocity() { return vy; }
	};
}
