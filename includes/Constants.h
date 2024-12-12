#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "SDL.h"
typedef SDL_Color Color;

// Constants for screen
const int W = 1600;
const int H = 1000;
const int FPS = 16;
const int GAME_IS_RUNNING = 1;

// CIRCLESSSSS
const double AREA_OF_SPAWN = 0.2;
const double COMPLEMENT = 1 - AREA_OF_SPAWN;
const int RADIUS = 2;
const int AMNT_CIRCLES = 1000;
const int SPEED = 1;

// math
const float PI = 3.14159;

#endif

