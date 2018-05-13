#pragma once
#ifndef _SNAKE_H
#define _SNAKE_H

#include<stdio.h>
#include<conio.h>

#include"screen.h"

#define ROW 40
#define COL 20

#define L 75
#define R 77
#define U 72
#define D 80

typedef enum _dir { LEFT, RIGHT, UP, DOWN } direction;

typedef struct _pos {
	int x;
	int y;
}pos;

typedef struct _object {
	pos heart;
	int eat;
}object;

typedef struct _snake {
	pos head;
	direction dir;
	pos tail[500];
	int die;//죽었으면 0 살았으면 1
}snake;

object *obj;
snake sn;
int N;
int taillength;

void init();
void update();
void draw();
void release();


#endif