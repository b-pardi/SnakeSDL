#include "../headers/Game.h"

Snake* snake = nullptr;

Game::Game()
{
	
}

Game::~Game()
{
	
}

void Game::initSDL(const char* title, int xpos, int ypos, int width, int height)
{
	int flags = 0;
	// creating window and renderer
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
			std::cout << "Window created" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			std::cout << "renderer created" << std::endl;
			SDL_SetRenderDrawColor(renderer, 111, 148, 96, 255);
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	// init positions of snake head
	snake = new Snake(300, 200, 20, 20);
	snake->initSnake();
	snake->velocity = 8;
	snake->body_len = 3;

}

void Game::update()
{
	if (snake->direction == 3)
		snake->snakeRect.x += snake->velocity;

	if (snake->direction == 6)
		snake->snakeRect.y += snake->velocity;

	if (snake->direction == 9)
		snake->snakeRect.x -= snake->velocity;

	if (snake->direction == 12)
		snake->snakeRect.y -= snake->velocity;
}

void Game::render()
{
	// clear previous position of snake and rerender background
	SDL_SetRenderDrawColor(renderer, 111,148,96,255);
	SDL_RenderClear(renderer);

	// render the snake head
	// location and size of rect to be filled
	SDL_Rect fillRect = { snake->snakeRect.x, snake->snakeRect.y, snake->snakeRect.w, snake->snakeRect.h };
	SDL_SetRenderDrawColor(renderer, 101, 122, 98, 255);
	SDL_RenderFillRect(renderer, &fillRect);

	int prevX = snake->bodyX[0];
	int prevY = snake->bodyY[0];
	snake->bodyX[0] = snake->snakeRect.x;
	snake->bodyY[0] = snake->snakeRect.y;
	int curX, curY;

	for (int i = 1; i < snake->body_len; i++)
	{
		// cursors set to where body piece currently is
		curX = snake->bodyX[i];
		curY = snake->bodyY[i];
		// now set tail to one in front of it
		snake->bodyX[i] = prevX;
		snake->bodyY[i] = prevY;
		// set prev to cursor to continue iteratively down the snake body
		prevX = curX;
		prevY = curY;

		// render the snake
		// location and size of rect to be filled
		SDL_Rect fillRect = { prevX, prevY, snake->snakeRect.w, snake->snakeRect.h };
		SDL_SetRenderDrawColor(renderer, 101, 122, 98, 255);
		SDL_RenderFillRect(renderer, &fillRect);
	}

	SDL_RenderPresent(renderer);
}

void Game::eventHandler()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	// check if user quit game
	case SDL_QUIT:
		isRunning = false;
		break;
	// check if user pressing arrow key
	case SDL_KEYDOWN:
		// snake directions correspond to clock directions
		switch (event.key.keysym.sym)
		{
		case SDLK_RIGHT:
			snake->direction = 3;
			break;
		case SDLK_DOWN:
			snake->direction = 6;
			break;
		case SDLK_LEFT:
			snake->direction = 9;
			break;
		case SDLK_UP:
			snake->direction = 12;
		}
	default:
		break;
	}
}

bool Game::checkRunning()
{
	return isRunning;
}

void Game::memoryClear()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game memory cleared" << std::endl;
}