#include <SFML/Graphics.hpp>
#include <cstdlib>

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "entity.hpp"
#endif

namespace pong {
	class Ball : public Entity
	{
	private:
		static const int height = 10;
		static const int width = 10;
		static const int INIT_VY = 300;
		static const int INIT_VX = 400;
		float random(float min, float max);
		
	public:
		Ball(float startX, float startY);
		
		void update(float delta);
		void hit();
		void render(sf::RenderWindow* window);
		void reset();
		
		const int getHeight() { return height; }
		const int getWidth() { return width; }
	};
}
