#ifndef _SIMULATION_ENGINE_H_
#define _SIMULATION_ENGINE_H_
/*
    This class is the main workhorse for the Monte Carlo
    simulation. 
    
    The idea is that things like simulation parameters, 
    including the Hamiltonian, are known at compile-time,
    and everything else can be implemented in this 
    encapsulated way at run-time. 
*/

template<class Hamiltonian_t>
class SimulationEngine
{
public:
    SimulationEngine();
    virtual ~SimulationEngine(){}

    void initialize();
    void thermalize();
    void measure();
    void analyze_statistics();
    void record_data();
};

template<class Hamiltonian_t>
SimulationEngine<Hamiltonian_t>::SimulationEngine()
{
    /* intentionally empty */
}

template<class Hamiltonian_t>
void SimulationEngine<Hamiltonian_t>::initialize()
{
    /* intentionally empty */
}

template<class Hamiltonian_t>
void SimulationEngine<Hamiltonian_t>::thermalize()
{
    /* intentionally empty */
}

template<class Hamiltonian_t>
void SimulationEngine<Hamiltonian_t>::measure()
{
    /* intentionally empty */
}

template<class Hamiltonian_t>
void SimulationEngine<Hamiltonian_t>::analyze_statistics()
{
    /* intentionally empty */
}

template<class Hamiltonian_t>
void SimulationEngine<Hamiltonian_t>::record_data()
{
    /* intentionally empty */
}


#endif // _SIMULATION_ENGINE_H_ 