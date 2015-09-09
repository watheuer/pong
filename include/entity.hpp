#include <SFML/Graphics.hpp>

namespace pong 
{
	class Entity
	{
	protected:
		sf::RectangleShape rect;
		float vx;
		float vy;
		
	public:
		virtual void update(float delta) {};
		sf::RectangleShape getRect() { return rect; }
		float getX() { return rect.getPosition().x; }
		float getY() { return rect.getPosition().y; }
		virtual const int getHeight() {};
		virtual const int getWidth() {};
		virtual void render(sf::RenderWindow* window) {};
	};
}