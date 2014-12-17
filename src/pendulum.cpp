#include "pendulum.h"

void Pendulum::update(float dt)
{
    x = parent->x + sin(angle + M_PI) * 50 * length;
    y = parent->y + cos(angle + M_PI) * 50 * length;
}

void Pendulum::draw(int height)
{
    al_draw_filled_circle(x, height-y, rad, al_map_rgb(r, g, b));
    al_draw_line(parent->x, height-(parent->y), x, height-y, al_map_rgb(255, 255, 255), 2);
}
