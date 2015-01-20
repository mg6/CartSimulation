#ifndef __PendulumCart__
#define __PendulumCart__

#include "primitives.hpp"
#include "pendulum.hpp"
#include "cart.hpp"

struct PendulumCart : public virtual Drawable
{
    PendulumCart(Simulation* parent, double x, double y, double w, double h);
    ~PendulumCart();

    double w;   // width
    double h;   // height
    double vx;  // velocity

    void update(double dt);
    void draw(int height);

    Simulation* parent;
    Cart* cart;
    Pendulum* pendulum;
};

#endif
