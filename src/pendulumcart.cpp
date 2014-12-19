#include "pendulumcart.hpp"

PendulumCart::PendulumCart(Simulation* parent, float x, float y, float w, float h)
{
    this->parent = parent;
    this->x = x;
    this->y = y;
    this->vx = 15;

    cart = new Cart(this, w, h, 5);
    pendulum = new Pendulum(this, 3, 10, 2, 10);
}

PendulumCart::~PendulumCart()
{
    delete cart;
    delete pendulum;
}

void PendulumCart::update(float dt)
{
    // from http://www.myphysicslab.com/pendulum_cart.html
    double sh = sin(pendulum->angle);
    double csh = cos(pendulum->angle);

    // velocity of cart
    // v' = (m w^2 L sin(h) + m g sin(h) cos(h) - k x)/(M + m sin^2(h))
    double numer = pendulum->mass * pow(pendulum->av, 2) * pendulum->length * sh + pendulum->mass * gravity * sh * csh;
    double denom = cart->mass + pendulum->mass * pow(sh, 2);
    double dv = numer/denom;

    // angular velocity of pendulum
    // w' = [-m w^2 L sin(h) cos(h) + k x cos(h) - (M+m)g sin(h)]/[L(M + m sin^2(h))]
    numer = -pendulum->mass * pow(pendulum->av, 2) * pendulum->length * sh * csh - (cart->mass + pendulum->mass) * gravity * sh;
    denom = pendulum->length * (cart->mass + pendulum->mass * pow(sh, 2));
    double da = numer/denom;

    // change to RK4
    vx += dv * dt;
    x += vx * dt;
    pendulum->av += da * dt;
    pendulum->angle += pendulum->av * dt;

    cart->update(dt);
    pendulum->update(dt);
}

void PendulumCart::draw(int height)
{
    cart->draw(height);
    pendulum->draw(height);
}

