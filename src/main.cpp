#include "common.h"
#include "simulation.h"

int main(int argc, char** argv)
{
    Simulation sim;

    sim.init();

    while (!sim.done())
    {
        sim.handle_events();
        sim.update(15);
        sim.draw();
    }

    sim.cleanup();

    return 0;
}
