#ifndef __Drawable__
#define __Drawable__

#include "common.hpp"

struct Drawable
{
    double x;
    double y;

    char r;
    char g;
    char b;

    virtual void draw(int height) = 0;
    virtual void setPos(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

#endif
