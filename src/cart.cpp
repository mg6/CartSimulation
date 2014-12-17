#include "cart.h"

void Cart::draw(int height)
{
    al_draw_filled_circle(parent->x-w/3, height-(parent->y-h/2), 10, al_map_rgb(255, 255, 255));
    al_draw_filled_circle(parent->x+w/3, height-(parent->y-h/2), 10, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(parent->x-w/2, height-(parent->y+h/2), parent->x+w/2, height-(parent->y-h/2), al_map_rgb(r, g, b));
}
