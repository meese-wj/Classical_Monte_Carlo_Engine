#include "SimulationEngine.hpp"

// TODO: Define this typedef later on when more 
// detail is filled out.
using MODEL_TYPE = double;

int main( int argc, char * argv [] )
{
    // Step 0: instantiate the simulation
    SimulationEngine<MODEL_TYPE> simulation;

    // Step 1: Setup simulation
    simulation.initialize();

    // Step 2: Equilibrate or load-in previous thermal ensemble
    simulation.thermalize();

    // Step 3: Measure the thermal ensemble
    simulation.measure();

    // Step 4: Properly bin the statistics and collect error bars
    simulation.analyze_statistics();

    // Step 5: send statistics and final configuration to a data directory
    simulation.record_data();

    return 0;
}