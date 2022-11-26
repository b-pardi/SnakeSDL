#include "../headers/Snake.h"

Snake::Snake(int snake_x, int snake_y, int snake_w, int snake_h)
{
	this->snake_x = snake_x;
	this->snake_y = snake_y;
	this->snake_w = snake_w;
	this->snake_h = snake_h;
}

void Snake::initSnake()
{
	snakeRect.x = snake_x;
	snakeRect.y = snake_y;
	snakeRect.w = snake_w;
	snakeRect.h = snake_h;
}