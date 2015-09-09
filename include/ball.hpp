#include <SFML/Graphics.hpp>
#include <cstdlib>

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "entity.hpp"
#endif

#ifndef SCORE_HPP
#define SCORE_HPP
#include "scoreboard.hpp"
#endif

#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "paddle.hpp"
#endif

namespace pong 
{
	class Ball : public Entity
	{
	private:
		static const int HEIGHT = 10;
		static const int WIDTH = 10;
		static const int INIT_SPEED= 450;
		static const float MAXBOUNCE = 1.047; // 60 degrees
		
		float speed;
		Scoreboard* scoreboard;
		
	public:
		Ball(float startX, float startY, pong::Scoreboard* scoreboard);
		
		void update(float delta);
		void hit(Paddle* paddle, int direction);
		void render(sf::RenderWindow* window);
		void reset(int direction);
		
		const int getHeight() { return HEIGHT; }
		const int getWidth() { return WIDTH; }
	};
}
