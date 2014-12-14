#include "cart.h"

Cart::Cart(float x, float y, float w, float h)
{
    m = 1;
    fx = 0;
    vx = 0;
    ax = 0;

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    ball = new Circle(x, y-3*h, 10, 255, 127, 0);
    cart = new Rectangle(x, y, w, h);
    wheel1 = new Circle(x-w/3, y-h/2, 10, 255, 255, 255);
    wheel2 = new Circle(x+w/3, y-h/2, 10, 255, 255, 255);
}

Cart::~Cart()
{
    delete ball;
    delete cart;
    delete wheel1;
    delete wheel2;
}

void Cart::update(float dt)
{
    ax = fx/m;
    vx += ax * dt;
    x += vx * dt;

    ball->setPos(x, y-3*h);
    cart->setPos(x, y);
    wheel1->setPos(x-w/3, y-h/2);
    wheel2->setPos(x+w/3, y-h/2);
}

void Cart::draw(int height)
{
    cart->draw(height);
    wheel1->draw(height);
    wheel2->draw(height);
    ball->draw(height);
    al_draw_line(cart->x, height-(cart->y), ball->x, height-(ball->y), al_map_rgb(255, 255, 255), 2);
}
