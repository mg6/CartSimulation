#ifndef __Simulation__
#define __Simulation__

#include "common.hpp"
#include "pendulumcart.hpp"

struct Simulation
{
    Simulation() : display(nullptr), queue(nullptr), redraw_timer(nullptr),
      update_timer(nullptr), _done(false), cart(nullptr), paused(false), font(nullptr) {}

    void init();
    void loop();
    bool handle_events();
    void update(float dt);
    void draw();
    void cleanup();
    bool done();

    bool _done;
    bool paused;
    static const int width = 800;
    static const int height = 600;
    const float fps = 60;
    const float updates_per_sec = 100;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_FONT* font;
    ALLEGRO_TIMER* redraw_timer;
    ALLEGRO_TIMER* update_timer;
    PendulumCart* cart;
};

#endif
