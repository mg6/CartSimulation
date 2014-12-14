#include "common.h"
#include "simulation.h"

int main(int argc, char** argv)
{
    Simulation sim;

    sim.init();
    sim.loop();
    sim.cleanup();

    return 0;
}
