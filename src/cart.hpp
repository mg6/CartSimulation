#ifndef __Cart__
#define __Cart__

#include "common.hpp"
#include "primitives.hpp"

struct Cart : public virtual Drawable
{
    Cart(Drawable* parent, float w, float h, float mass) : parent(parent), w(w), h(h), mass(mass)
    {
        r = 255;
        g = 127;
        b = 0;
    }

    void update(float dt) {}
    void draw(int height);

    float w;
    float h;
    float mass;

    Drawable* parent;
};

#endif
