#ifndef __Circle__
#define __Circle__

#include "common.h"
#include "drawable.h"

struct Rectangle : Drawable
{
    float x;
    float y;
    float w;
    float h;
    float r;
    float g;
    float b;

    Rectangle(float x, float y, float w, float h, char r = 255, char g = 0, char b = 0) : x(x), y(y), w(w), h(h), r(r), g(g), b(b) {}

    void draw()
    {
        al_draw_filled_rectangle(x, y, x+w, y+h, al_map_rgb(r, g, b));
    }
};

struct Circle : Drawable
{
    float x;
    float y;
    float rad;
    char r;
    char g;
    char b;

    Circle(float x, float y, float rad, char r = 255, char g = 0, char b = 0) : x(x), y(y), rad(rad), r(r), g(g), b(b) {}

    void draw()
    {
        al_draw_filled_circle(x, y, rad, al_map_rgb(r, g, b));
    }
};

#endif
