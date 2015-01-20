#ifndef __Cart__
#define __Cart__

#include "common.hpp"
#include "primitives.hpp"

struct Cart : public virtual Drawable
{
    Cart(PendulumCart* parent, float w, float h, float mass) :
        parent(parent), w(w), h(h), mass(mass) {}

    void update(float dt) {}
    void draw(int height);

    float w;
    float h;
    float mass;

    PendulumCart* parent;
};

#endif
