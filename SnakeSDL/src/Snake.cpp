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

Fruit::Fruit(int fruit_x, int fruit_y, int fruit_w, int fruit_h)
{
	this->fruit_x = fruit_x;
	this->fruit_y = fruit_y;
	this->fruit_w = fruit_w;
	this->fruit_h = fruit_h;
}

void Fruit::initFruit()
{
	fruitRect.x = fruit_x;
	fruitRect.y = fruit_y;
	fruitRect.w = fruit_w;
	fruitRect.h = fruit_h;

}

// uses random number generator to determine new x and y coordinates for the fruit
void Fruit::nextPosition(int lower_x, int upper_x, int lower_y, int upper_y)
{
	int xrand = lower_x + rand() % upper_x;
	fruitRect.x = xrand;
	
	int yrand = lower_y + rand() % upper_y;
	fruitRect.y = yrand;
}
