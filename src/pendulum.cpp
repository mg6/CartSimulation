#include "pendulum.hpp"

void Pendulum::update(float dt)
{
    if (angle < -M_PI*2)
        angle += M_PI*2;
    else if (angle > M_PI*2)
        angle -= M_PI*2;

    x = parent->x + sin(angle + M_PI) * 50 * length;
    y = parent->y + cos(angle + M_PI) * 50 * length;
}

void Pendulum::draw(int height)
{
    al_draw_filled_circle(x, height-y, rad, al_map_rgb(r, g, b));
    al_draw_line(parent->x, height-(parent->y), x, height-y, al_map_rgb(255, 255, 255), 2);
    al_draw_line(parent->x, height-(parent->y), parent->x, height-(parent->y - 50), al_map_rgb(255, 255, 255), 1);
    al_draw_arc(parent->x, height-(parent->y), 50, M_PI/2, angle, al_map_rgb(255, 255, 255), 1);
}
