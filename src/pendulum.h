#ifndef __Pendulum__
#define __Pendulum__

#include "common.h"
#include "primitives.h"

struct Pendulum : public virtual Drawable
{
    Pendulum(Drawable* parent, float length, float mass, float velo, float rad) : parent(parent), length(length), mass(mass), rad(rad), av(velo)
    {
        x = parent->x;
        y = parent->y - 100;
        r = 255;
        g = 255;
        b = 255;
    }

    ~Pendulum() {};

    void update(float dt);
    void draw(int height);

    Drawable* parent;
    float x;
    float y;
    float angle;
    float av; // angular velocity
    float length;
    float mass;
    float rad;
};

#endif