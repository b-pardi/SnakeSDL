#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include "Snake.h"

class Game
{
public:
	Game();
	~Game();
	
	// initializing SDL
	void initSDL(const char* title, int xpos, int ypos, int width, int height);
	void update();
	bool checkRunning();
	void render();
	void eventHandler();
	void memoryClear();

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif // GAME_H