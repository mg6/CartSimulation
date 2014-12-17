#include "pendulumcart.hpp"

PendulumCart::PendulumCart(float x, float y, float w, float h)
{
    this->x = x;
    this->y = y;

    cart = new Cart(this, w, h, 100);
    pendulum = new Pendulum(this, 3, 10, 1, 10);
}

PendulumCart::~PendulumCart()
{
    delete cart;
    delete pendulum;
}

void PendulumCart::update(float dt)
{
    double sh = sin(pendulum->angle);
    double csh = cos(pendulum->angle);
    double cs2h = pow(csh, 2) - pow(sh, 2);

    const double k = 0.25;

    //v' = (m w^2 L sin(h) + m g sin(h) cos(h) - k x)/(M + m sin^2(h))
    double numer = pendulum->mass * pow(pendulum->av, 2) * pendulum->length * sh + pendulum->mass * gravity * sh * csh - k * x;
    double denom = cart->mass + pendulum->mass * pow(sh, 2);
    double dv = numer/denom;

    //w' = [-m w^2 L sin(h) cos(h) + k x cos(h) - (M+m)g sin(h)]/[L(M + m sin^2(h))]
    numer = -pendulum->mass * pow(pendulum->av, 2) * pendulum->length * sh * csh + k * x * csh - (cart->mass + pendulum->mass) * gravity * sh;
    denom = pendulum->length * (cart->mass + pendulum->mass * pow(sh, 2));
    double da = numer/denom;

    x += vx * dt;
    pendulum->angle += pendulum->av * dt;
    vx += dv * dt;
    pendulum->av += da * dt;

    cart->update(dt);
    pendulum->update(dt);
}

void PendulumCart::draw(int height)
{
    cart->draw(height);
    pendulum->draw(height);
}

