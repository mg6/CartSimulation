#ifndef __Pendulum__
#define __Pendulum__

#include "common.hpp"
#include "primitives.hpp"

struct Pendulum : public virtual Drawable
{
    Pendulum(Drawable* parent, double length, double mass, double velo, double rad) : parent(parent), length(length), mass(mass), rad(rad), av(velo)
    {
        x = parent->x;
        y = parent->y - 100;
    }

    ~Pendulum() {};

    void update(double dt);
    void draw(int height);

    Drawable* parent;
    double x;
    double y;
    double angle;
    double av; // angular velocity
    double length;
    double mass;
    double rad;
};

#endif
