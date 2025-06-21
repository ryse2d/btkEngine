#include <iostream>
#include <SDL2/SDL.h>
#include "../Engine/Core/Game.h"
using namespace std;

int main(int argc, char* argv[]) {
	Game game;
	if (!game.Init("BTKENGINE", 1280, 720))
		return -1;

	game.Run();
	return 0;
}