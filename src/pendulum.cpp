#include "pendulum.hpp"

void Pendulum::update(double dt)
{
    if (angle < -M_PI*2)
        angle += M_PI*2;
    else if (angle > M_PI*2)
        angle -= M_PI*2;

    x = parent->x + sin(angle + M_PI) * 50.0 * length;
    y = parent->y + cos(angle + M_PI) * 50.0 * length;
}

void Pendulum::draw(int height)
{
    // angle
    al_draw_line(parent->x, height-(parent->y), parent->x, height-(parent->y - 60), al_map_rgb(COL_ANGLE), 3);
    al_draw_arc(parent->x, height-(parent->y), 50, M_PI/2, angle, al_map_rgb(COL_ANGLE), 3);

    // spring
    al_draw_line(parent->x, height-(parent->y), x, height-y, al_map_rgb(COL_PENDULUM), 3);

    // mass
    al_draw_filled_circle(x, height-y, mass/10.0, al_map_rgb(COL_PENDULUM));
}
