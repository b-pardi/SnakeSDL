#include "SDL.h"
#include "../headers/Game.h"
#include "../headers/Snake.h"

Game* game = nullptr;


int main(int argc, char* argv[])
{
	// refresh rate of game
	const int fps = 60;
	// max time between frames
	const int frameDelay = 1000 / fps;
	
	Uint32 frameBegin;
	int frameTime;

	// creating window and renderer
	game = new Game();
	                                                                       // boundries 
	game->initSDL("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480);;

	while (game->checkRunning())
	{
		frameBegin = SDL_GetTicks();

		game->eventHandler();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameBegin;

		// delay next frame to ensure 60fps
		if (frameDelay > frameTime)
		{
			SDL_Delay(2*(frameDelay - frameTime));
		}
	}

	game->memoryClear();

	return 0;
}