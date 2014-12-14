#ifndef __Circle__
#define __Circle__

#include "common.h"
#include "drawable.h"

struct Rectangle : public virtual Drawable
{
    float w;
    float h;

    Rectangle(float x, float y, float w, float h, char r = 255, char g = 0, char b = 0) : w(w), h(h)
    {
        this->x = x;
        this->y = y;
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void draw(int height)
    {
        al_draw_filled_rectangle(x-w/2, height-(y+h/2), x+w/2, height-(y-h/2), al_map_rgb(r, g, b));
    }
};

struct Circle : public virtual Drawable
{
    float rad;

    Circle(float x, float y, float rad, char r = 255, char g = 0, char b = 0) : rad(rad)
    {
        this->x = x;
        this->y = y;
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void draw(int height)
    {
        al_draw_filled_circle(x, height-y, rad, al_map_rgb(r, g, b));
    }
};

#endif
