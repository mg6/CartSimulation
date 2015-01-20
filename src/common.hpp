#ifndef __Common__
#define __Common__

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdarg>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

const float gravity = 9.81;

struct Cart;
struct Pendulum;
struct PendulumCart;
struct Simulation;

#define COL_ANGLE       255, 0, 0
#define COL_BACKGROUND  255, 255, 255
#define COL_CART        255, 127, 0
#define COL_PENDULUM    0, 0, 0
#define COL_TEXT        0, 0, 0
#define COL_VELOCITY    0, 0, 255
#define COL_WHEELS      127, 127, 127

#endif
