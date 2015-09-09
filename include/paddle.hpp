#include <SFML/Graphics.hpp>

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "entity.hpp"
#endif

namespace pong {
	class Paddle : public Entity
	{
	private:
		float speed;
		static const int height = 80;
		static const int width = 10;
		
	public:
		Paddle(float startX, float startY, float speed);
		void update(float delta);
		bool moveUp;
		bool moveDown;
		void render(sf::RenderWindow* window);
		const int getHeight() { return height; }
		const int getWidth() { return width; }
		float getVelocity() { return vy; }
	};
}
