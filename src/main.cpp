#include "common.hpp"
#include "simulation.hpp"

int main(int argc, char** argv)
{
    Simulation sim;

    sim.init();
    sim.loop();
    sim.cleanup();

    return 0;
}
