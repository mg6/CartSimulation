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

    if (!(redraw_timer = al_create_timer(1.0/fps)))
        exit(1);

    if (!(update_timer = al_create_timer(1.0/updates_per_sec)))
        exit(1);

    if (!(display = al_create_display(width, height)))
        exit(1);

    if (!(queue = al_create_event_queue()))
        exit(1);

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(redraw_timer));
    al_register_event_source(queue, al_get_timer_event_source(update_timer));

    al_start_timer(redraw_timer);
    al_start_timer(update_timer);

    cart = new PendulumCart(100, 500, 100, 50);
}

void Simulation::loop()
{
    ALLEGRO_EVENT e;
    bool redraw = false;

    while (!done())
    {
        al_wait_for_event(queue, &e);

        switch (e.type)
        {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                _done = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                switch (e.keyboard.keycode)
                {
                    case ALLEGRO_KEY_P:
                        paused = !paused;
                        break;
                    case ALLEGRO_KEY_Q:
                    case ALLEGRO_KEY_ESCAPE:
                        _done = true;
                        break;
                    case ALLEGRO_KEY_LEFT:
                        cart->fx -= 5;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        cart->fx += 5;
                        break;
                }
                break;

            case ALLEGRO_EVENT_TIMER:
                if (e.timer.source == update_timer)
                {
                    static float old_time = 0;
                    float cur_time = al_get_time();
                    if (!paused) update(cur_time - old_time);
                    old_time = cur_time;
                }
                else if (e.timer.source == redraw_timer)
                {
                    redraw = true;
                }
                break;
        }

        if (redraw && al_is_event_queue_empty(queue))
        {
            redraw = false;
            draw();
        }
    }
}

void Simulation::update(float dt)
{
    cart->update(dt);
}

void Simulation::draw()
{
    al_clear_to_color(al_map_rgb(bgr, bgg, bgb));
    cart->draw(height);
    al_flip_display();
}

void Simulation::cleanup()
{
    if (redraw_timer)
        al_destroy_timer(redraw_timer);

    if (update_timer)
        al_destroy_timer(update_timer);

    if (display)
        al_destroy_display(display);

    if (queue)
        al_destroy_event_queue(queue);

    delete cart;
}

bool Simulation::done()
{
    return _done;
}
