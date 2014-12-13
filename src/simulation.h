#ifndef __Simulation__
#define __Simulation__

#include "common.h"
#include "primitives.h"

struct Simulation
{
    Simulation() : display(nullptr), queue(nullptr), timer(nullptr), _done(false), r(32), g(32), b(32) {}

    void init();
    void handle_events();
    void update(unsigned dt);
    void draw();
    void cleanup();
    bool done();

    bool _done;
    char r;
    char g;
    char b;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_TIMER* timer;
};

#endif
