#ifndef __Simulation__
#define __Simulation__

#include "common.h"
#include "pendulumcart.h"

struct Simulation
{
    Simulation() : display(nullptr), queue(nullptr), redraw_timer(nullptr),
      update_timer(nullptr), _done(false), bgr(32), bgg(32), bgb(32),
      cart(nullptr), width(800), height(600), paused(false) {}

    void init();
    void loop();
    bool handle_events();
    void update(float dt);
    void draw();
    void cleanup();
    bool done();

    bool _done;
    bool paused;
    char bgr;
    char bgg;
    char bgb;
    int width;
    int height;
    const float fps = 60;
    const float updates_per_sec = 100;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_TIMER* redraw_timer;
    ALLEGRO_TIMER* update_timer;
    PendulumCart* cart;
};

#endif
