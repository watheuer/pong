#include "scoreboard.hpp"
#include <SFML/Graphics.hpp>
#include <stdio.h>

namespace pong 
{
	Scoreboard::Scoreboard(int max):
	leftScore(0), rightScore(0), maxScore(max), leftWin(false), rightWin(false)
	{
		if (!font.loadFromFile("Roboto-Regular.ttf"))
		{
			// shit
		}
		text1.setFont(font);
		text1.setStyle(sf::Text::Regular);
		text1.setCharacterSize(60);
		text1.setColor(sf::Color::White);
		
		text2.setFont(font);
		text2.setStyle(sf::Text::Regular);
		text2.setCharacterSize(60);
		text2.setColor(sf::Color::White);
	}
	
	void Scoreboard::render(sf::RenderWindow* window)
	{
		char buf[4];
		sprintf(buf, "%d", leftScore);
		text1.setString(buf);
		text1.setPosition(350-text1.getGlobalBounds().width/2, 20);
		
		sprintf(buf, "%d", rightScore);
		text2.setString(buf);
		text2.setPosition(450-text2.getGlobalBounds().width/2, 20);
		
		window->draw(text1);
		window->draw(text2);
	}
	
	void Scoreboard::scoreLeft()
	{
		if (leftScore < maxScore)
		{
			leftScore++;
		} else {
			leftWin = true;
		}
	}
	
	void Scoreboard::scoreRight()
	{
		if (rightScore < maxScore)
		{
			rightScore++;
		} else {
			rightWin = true;
		}
	}
}