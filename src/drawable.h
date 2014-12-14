#ifndef __Drawable__
#define __Drawable__

#include "common.h"

struct Drawable
{
    float x;
    float y;

    char r;
    char g;
    char b;

    virtual void draw(int height) = 0;
    virtual void setPos(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};

#endif
