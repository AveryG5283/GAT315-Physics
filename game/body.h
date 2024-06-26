#pragma once
#include "raylib.h"


typedef struct Body
{
	// force -> acceleration -> velocity -> position
	Vector2 position;
	Vector2 velocity;
	Vector2 force;

	struct Body* next;
	struct Body* prev;
} Body;