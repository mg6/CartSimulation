#include "cart.hpp"
#include "pendulumcart.hpp"
#include "simulation.hpp"

void Cart::draw(int height)
{
    // wheels
    al_draw_filled_circle(parent->x-w/3, height-(parent->y-h/2), 10, al_map_rgb(COL_WHEELS));
    al_draw_filled_circle(parent->x+w/3, height-(parent->y-h/2), 10, al_map_rgb(COL_WHEELS));

    // cart
    al_draw_filled_rectangle(parent->x-w/2, height-(parent->y+h/2), parent->x+w/2, height-(parent->y-h/2), al_map_rgb(COL_CART));

    // velocity vector
    al_draw_line(parent->x, parent->y, parent->x + parent->vx*2, parent->y, al_map_rgb(COL_VELOCITY), 3);

    // arrow
    al_draw_line(parent->x + parent->vx*2, parent->y, parent->x + parent->vx*2 - (parent->vx > 0 ? 1 : -1) * 15, height-(parent->y - 5), al_map_rgb(COL_VELOCITY), 3);
    al_draw_line(parent->x + parent->vx*2, parent->y, parent->x + parent->vx*2 - (parent->vx > 0 ? 1 : -1) * 15, height-(parent->y + 5), al_map_rgb(COL_VELOCITY), 3);
}
