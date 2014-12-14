#ifndef __Cart__
#define __Cart__

#include "primitives.h"

struct Cart : public virtual Drawable
{
    Cart(float x, float y, float w, float h);
    ~Cart();

    float w;    // width
    float h;    // height

    float m;    // mass
    float fx;   // force
    float vx;   // velocity
    float ax;   // acceleration

    void update(float dt);
    void draw(int height);

    Circle* ball;
    Circle* wheel1;
    Circle* wheel2;
    Rectangle* cart;
};

#endif
