#include "../headers/Snake.h"

// snake objcet that carries size and location of snake pieces
Snake::Snake(int snake_x, int snake_y, int snake_w, int snake_h)
{
	this->snake_x = snake_x;
	this->snake_y = snake_y;
	this->snake_w = snake_w;
	this->snake_h = snake_h;
}

// use values from constructor to create an SDL rectangle for the snake
void Snake::initSnake()
{
	snakeRect.x = snake_x;
	snakeRect.y = snake_y;
	snakeRect.w = snake_w;
	snakeRect.h = snake_h;
}