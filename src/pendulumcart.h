#ifndef __PendulumCart__
#define __PendulumCart__

#include "primitives.h"
#include "pendulum.h"
#include "cart.h"

struct PendulumCart : public virtual Drawable
{
    PendulumCart(float x, float y, float w, float h);
    ~PendulumCart();

    float w;    // width
    float h;    // height
    float vx;   // velocity

    void update(float dt);
    void draw(int height);

    Cart* cart;
    Pendulum* pendulum;
};

#endif
