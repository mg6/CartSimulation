#include "primitives.hpp"
#include "simulation.hpp"

void Simulation::init()
{
    if (!al_init())
    {
        std::cerr << "Error: Allegro initialization failed." << std::endl;
        exit(1);
    }

    al_init_font_addon();

    if (!al_init_ttf_addon())
    {
        std::cerr << "Error: TTF addon initialization failed." << std::endl;
        exit(1);
    }

    if (!al_install_keyboard())
    {
        std::cerr << "Error: Keyboard installation failed." << std::endl;
        exit(1);
    }

    if (!(font = al_load_ttf_font("DejaVuSans.ttf", 16, 0)))
    {
        std::cerr << "Error: DejaVuSans.ttf is missing." << std::endl;
        exit(1);
    }

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

    if (!(redraw_timer = al_create_timer(1.0/fps)))
    {
        std::cerr << "Error: Could not create redraw timer." << std::endl;
        exit(1);
    }

    if (!(update_timer = al_create_timer(1.0/updates_per_sec)))
    {
        std::cerr << "Error: Could not create update timer." << std::endl;
        exit(1);
    }

    if (!(display = al_create_display(width, height)))
    {
        std::cerr << "Error: Display installation failed." << std::endl;
        exit(1);
    }

    al_set_window_title(display, "Cart & pendulum");

    if (!(queue = al_create_event_queue()))
    {
        std::cerr << "Error: Event queue installation failed." << std::endl;
        exit(1);
    }

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(redraw_timer));
    al_register_event_source(queue, al_get_timer_event_source(update_timer));

    al_start_timer(redraw_timer);
    al_start_timer(update_timer);

    cart = new PendulumCart(this, 100, 300, 100, 50);

    std::cout << "Info: Initialization succeeded." << std::endl;
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
                        std::cout << "Simulation " << (paused ? "paused" : "unpaused") << std::endl;
                        break;

                    case ALLEGRO_KEY_Q:
                    case ALLEGRO_KEY_ESCAPE:
                        _done = true;
                        break;

                    case ALLEGRO_KEY_LEFT:
                        cart->vx -= 10;
                        std::cout << "Cart velocity = " << cart->vx << std::endl;
                        break;

                    case ALLEGRO_KEY_RIGHT:
                        cart->vx += 10;
                        std::cout << "Cart velocity = " << cart->vx << std::endl;
                        break;

                    case ALLEGRO_KEY_D:
                        cart->vx = -cart->vx;
                        std::cout << "Cart inverted = " << cart->vx << std::endl;
                        break;

                    case ALLEGRO_KEY_UP:
                        cart->pendulum->av += 0.5;
                        std::cout << "Pendulum angular velocity = " << cart->pendulum->av << std::endl;
                        break;

                    case ALLEGRO_KEY_DOWN:
                        if (cart->pendulum->av > 0.5)
                            cart->pendulum->av -= 0.5;
                        std::cout << "Pendulum angular velocity = " << cart->pendulum->av << std::endl;
                        break;

                    case ALLEGRO_KEY_L:
                        if (cart->pendulum->length > 1)
                            cart->pendulum->length--;
                        std::cout << "Pendulum length = " << cart->pendulum->length << std::endl;
                        break;

                    case ALLEGRO_KEY_O:
                        cart->pendulum->length++;
                        std::cout << "Pendulum length = " << cart->pendulum->length << std::endl;
                        break;

                    case ALLEGRO_KEY_J:
                        cart->pendulum->mass -= 10;
                        std::cout << "Pendulum mass = " << cart->pendulum->mass << std::endl;
                        break;

                    case ALLEGRO_KEY_U:
                        cart->pendulum->mass += 10;
                        std::cout << "Pendulum mass = " << cart->pendulum->mass << std::endl;
                        break;

                    case ALLEGRO_KEY_G:
                        cart->cart->mass -= 10;
                        std::cout << "Cart mass = " << cart->cart->mass << std::endl;
                        break;

                    case ALLEGRO_KEY_T:
                        cart->cart->mass += 10;
                        std::cout << "Cart mass = " << cart->cart->mass << std::endl;
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

#ifdef __GNUC__
#   define puts(x, y, args...) al_draw_textf(font, al_map_rgb(255, 255, 255), x, y, 0, args)
#else
#   define puts(x, y, ...)     al_draw_textf(font, al_map_rgb(255, 255, 255), x, y, 0, __VA_ARGS__)
#endif

void Simulation::draw()
{
    al_clear_to_color(al_map_rgb(bgr, bgg, bgb));
    cart->draw(height);
    puts(5, 5, "Cart: mass = %.2f, vx = %.2f, x = %.2f", cart->cart->mass, cart->vx, cart->x);
    puts(5, 21, "Pendulum: mass = %.2f, length = %.2lf, angle = %.2lf rad, angular v = %.2lf",
            cart->pendulum->mass, cart->pendulum->length, cart->pendulum->angle, cart->pendulum->av);
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

    if (font)
        al_destroy_font(font);

    if (queue)
        al_destroy_event_queue(queue);

    delete cart;

    std::cout << "Info: Finished successfuly." << std::endl;
}

bool Simulation::done()
{
    return _done;
}

