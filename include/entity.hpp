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
		virtual const int getHeight() {};
		virtual const int getWidth() {};
		virtual void render(sf::RenderWindow* window) {};
	};
}