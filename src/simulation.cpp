#include "primitives.h"
#include "simulation.h"

void Simulation::init()
{
    if (!al_init())
        exit(1);

    if (!al_install_keyboard())
        exit(1);

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

    if (!(timer = al_create_timer(1.0/60)))
        exit(1);

    if (!(display = al_create_display(800, 600)))
        exit(1);

    if (!(queue = al_create_event_queue()))
        exit(1);

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    al_start_timer(timer);
}

void Simulation::handle_events()
{
    ALLEGRO_EVENT e;

    if (al_is_event_queue_empty(queue))
        return;

    al_wait_for_event(queue, &e);

    switch (e.type)
    {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            _done = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
            switch (e.keyboard.keycode)
            {
                case ALLEGRO_KEY_Q:
                case ALLEGRO_KEY_ESCAPE:
                  _done = true;
                  break;
            }
            break;
    }
}

void Simulation::update(unsigned dt)
{
}

void Simulation::draw()
{
    al_clear_to_color(al_map_rgb(r, g, b));
    al_flip_display();
}

void Simulation::cleanup()
{
    if (timer)
        al_destroy_timer(timer);

    if (display)
        al_destroy_display(display);

    if (queue)
        al_destroy_event_queue(queue);
}

bool Simulation::done()
{
    return _done;
}
