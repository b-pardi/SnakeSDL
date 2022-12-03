#ifndef SNAKE_H
#define SNAKE_H

#include "SDL.h"

class Snake
{
public:
	SDL_Rect snakeRect;
	int snake_x, snake_y, snake_w, snake_h;
	int direction, velocity;
	int bodyX[200], bodyY[200];
	int body_len;


	Snake(int snake_x, int snake_y, int snake_w, int snake_h);
	~Snake();

	void initSnake();
};


class Fruit
{
public:
	SDL_Rect fruitRect;
	int fruit_x, fruit_y, fruit_w, fruit_h;
	int direction, velocity;
	int bodyX[200], bodyY[200];
	int body_len;


	Fruit(int fruit_x, int fruit_y, int fruit_w, int fruit_h);
	~Fruit();

	void initFruit();
};

#endif // SNAKE_H