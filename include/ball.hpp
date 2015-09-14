#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
		static const int INIT_SPEED = 450;
		static const int INIT_X = 400;
		static const int INIT_Y = 0;
		const float MAXBOUNCE;
		const float INIT_ANGLE;
		const float VARIATION;
		
		sf::SoundBuffer paddleBuffer;
		sf::SoundBuffer sideBuffer;
		sf::SoundBuffer scoreBuffer;
		sf::Sound paddleSound;
		sf::Sound sideSound;
		sf::Sound scoreSound;
		
		float speed;
		Scoreboard* scoreboard;
		
	public:
		Ball(pong::Scoreboard* scoreboard);
		
		void update(float delta);
		void hit(Paddle* paddle, int direction);
		void render(sf::RenderWindow* window);
		void reset(int direction);
		
		const int getHeight() { return HEIGHT; }
		const int getWidth() { return WIDTH; }
	};
}
