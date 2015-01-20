#ifndef __PendulumCart__
#define __PendulumCart__

#include "primitives.hpp"
#include "pendulum.hpp"
#include "cart.hpp"

struct PendulumCart : public virtual Drawable
{
    PendulumCart(Simulation* parent, float x, float y, float w, float h);
    ~PendulumCart();

    float w;    // width
    float h;    // height
    float vx;   // velocity

    void update(float dt);
    void draw(int height);

    Simulation* parent;
    Cart* cart;
    Pendulum* pendulum;
};

#endif
