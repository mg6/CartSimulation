#ifndef __Cart__
#define __Cart__

#include "common.hpp"
#include "primitives.hpp"

struct Cart : public virtual Drawable
{
    Cart(PendulumCart* parent, double w, double h, double mass) :
        parent(parent), w(w), h(h), mass(mass) {}

    void update(double dt) {}
    void draw(int height);

    double w;
    double h;
    double mass;

    PendulumCart* parent;
};

#endif
