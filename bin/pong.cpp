#include <SFML/Graphics.hpp>
#include <vector>
#include "game.hpp"

int main(int argc, char** argv)
{
	srand(time(0));
	Game game;
	game.run();
	
	return 0;
}